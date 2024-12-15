#include "vector.h"
#include <stdlib.h>
#include <string.h>

HVector create_vector_with_capacity(size_t cap)
{
	HVector hvec = (HVector)malloc(sizeof(Vector));
	if (hvec == NULL) {
		return NULL;
	}
	hvec->msize = 0;
	hvec->mcap = cap;
	hvec->mp = (DATATYPE*)malloc(cap * sizeof(DATATYPE));
	if (hvec->mp == NULL) {
		free(hvec);
		return NULL;
	}

	return hvec; 
}

//============================================================================
//============================================================================

HVector create_vector(void)
{
	return create_vector_with_capacity(DEFAULT_CAP);
}

//============================================================================
//============================================================================

HVector create_vector_with_array(const DATATYPE* p, size_t size)
{
	HVector hvec = create_vector_with_capacity(size);
	if (hvec == NULL) {
		return NULL;
	}

	hvec->msize = size;
	
	memmove(hvec->mp, p, sizeof(DATATYPE) * size);

	return hvec;

}

//============================================================================
//============================================================================

HVector create_filled_vector(size_t size, DATATYPE val)
{
	HVector hvec = create_vector_with_capacity(size);
	if (hvec == NULL) {
		return NULL;
	}

	hvec->msize = size;

	for (size_t i = 0; i < hvec->msize; ++i) {

		hvec->mp[i] = val;
	}

	return hvec;

}

//============================================================================
//============================================================================

void destroy_vector(HVector hvec)
{
	free(hvec->mp);
	free(hvec);
}

//============================================================================
//============================================================================

int set_capacity(HVector hvec, size_t newcap)
{
	if (newcap < hvec->mcap) 
		return 0;
	

	if (newcap == hvec->mcap) 
		return 1;
	
	DATATYPE *pbuf = (DATATYPE * )realloc(hvec->mp, newcap * sizeof(DATATYPE));
	if (pbuf == NULL) {
		return 0;
	}

	hvec->mcap = newcap;
	hvec->mp = pbuf;

	return 1;
}

//============================================================================
//============================================================================

int push_back(HVector hvec, DATATYPE val)
{
	if (hvec->msize == hvec->mcap && !set_capacity(hvec, hvec->mcap * 2)) 
		return 0;
	
	hvec->mp[hvec->msize] = val;
	++hvec->msize;

	return 1;

}

//============================================================================
//============================================================================

int insert(HVector hvec, size_t idx, DATATYPE val)
{
	if (idx > hvec->msize)
		return 0; // gecersiz index

	if (hvec->msize == hvec->mcap && !set_capacity(hvec, hvec->mcap * 2))
		return 0;

	memmove(hvec->mp + idx + 1, hvec->mp + idx, (hvec->msize - idx) * sizeof(DATATYPE));

	hvec->mp[idx] = val;
	++hvec->msize;

	return 1;

}

//============================================================================
//============================================================================


int pop_back(HVector hvec)
{
	if (hvec->msize == 0)
		return 0;

	--hvec->msize;
	return 1;
}

//============================================================================
//============================================================================


int erase_idx(HVector hvec, size_t idx)
{
	
	if (idx >= hvec->msize)
		return 0; // gecersiz index

	memmove(hvec->mp + idx, hvec->mp + idx + 1, (hvec->msize - idx - 1) * sizeof(DATATYPE));
	--hvec->msize;

	return 1;
}

//============================================================================
//============================================================================

int erase_val(HVector hvec, DATATYPE val)
{
	size_t idx = find_val(hvec, val);
	if (idx == NOT_FOUND)
		return 0;

	return erase_idx(hvec, idx);
}

//============================================================================
//============================================================================

size_t erase_all(HVector hvec, DATATYPE val)
{
	size_t write_idx = 0;

	for (size_t i = 0; i < hvec->msize; ++i) {

		if (hvec->mp[i] != val) {
			hvec->mp[write_idx++] = hvec->mp[i];
		}
	}

	size_t erased = hvec->msize - write_idx;
	hvec->msize = write_idx;

	return erased;
}

//============================================================================
//============================================================================


int is_emptyvec(HVector hvec)
{
	return hvec->msize == 0;
}

//============================================================================
//============================================================================

size_t find_val(HVector hvec, DATATYPE val)
{
	for (size_t i = 0; i < hvec->msize; ++i) {

		if (val == hvec->mp[i])
			return i;
	}

	return NOT_FOUND;
}

//============================================================================
//============================================================================


void shrink_cap(HVector hvec)
{
	hvec->mp = (DATATYPE*)realloc(hvec->mp, hvec->msize * sizeof(DATATYPE));

	hvec->mcap = hvec->msize;

}

//============================================================================
//============================================================================

void clear(HVector hvec)
{
	hvec->msize = 0;
}

//============================================================================
//============================================================================
