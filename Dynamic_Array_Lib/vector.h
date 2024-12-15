#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>


#define get_size(hvec)				((hvec)->msize)
#define get_capacity(hvec)			((hvec)->mcap)
#define get_item(hvec, idx)	        ((hvec)->mp[idx])



#define NOT_FOUND       ((size_t)(-1))
#define DEFAULT_CAP     12

typedef int DATATYPE;

typedef struct tagVector {
	DATATYPE* mp;
	size_t msize;
	size_t mcap;
}Vector, *HVector;


HVector create_vector(void);
HVector create_vector_with_capacity(size_t cap);
HVector create_vector_with_array(const DATATYPE* p, size_t size);
HVector create_filled_vector(size_t size, DATATYPE val);

void destroy_vector(HVector);

int push_back(HVector, DATATYPE);
int pop_back(HVector);
int insert(HVector, size_t idx, DATATYPE val);


int set_capacity(HVector, size_t newcap);

void shrink_cap(HVector); // capacity'i küçültme

int erase_idx(HVector, size_t idx);
int erase_val(HVector, DATATYPE val);
size_t erase_all(HVector, DATATYPE val);

int is_emptyvec(HVector);

size_t find_val(HVector, DATATYPE val); // baþarýsýz durumun UINT_MAX deðeri

void clear(HVector);


// functional macros

  





#endif