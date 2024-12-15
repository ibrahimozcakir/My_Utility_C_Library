#ifndef MYCTYPE_H
#define MYCTYPE_H


#define      UPPER      0x01
#define      LOWER      0x02
#define      DIGIT      0x04
#define      XDIGIT     0x08
#define      PUNCT      0x10
#define      SPACE      0x20
#define      PRINT      0x40
#define      BLANK      0x80
#define      GRAPH      0x100
#define      CNTRL      0x200

extern const int myctype_[];

#define  ISUPPER(c)     (myctype_[c] & UPPER)
#define  ISLOWER(c)     (myctype_[c] & LOWER)
#define  ISALPHA(c)     (myctype_[c] & (UPPER | LOWER)) 
#define  ISALNUM(c)     (myctype_[c] & (UPPER | LOWER | DIGIT)) 
#define  ISDIGIT(c)     (myctype_[c] & DIGIT)
#define  ISXDIGIT(c)    (myctype_[c] & XDIGIT)
#define  ISPUNCT(c)     (myctype_[c] & PUNCT)
#define  ISSPACE(c)     (myctype_[c] & SPACE)
#define  ISPRINT(c)     (myctype_[c] & PRINT)
#define  ISBLANK(c)     (myctype_[c] & BLANK)
#define  ISGRAPH(c)     (myctype_[c] & GRAPH)
#define  ISCNTRL(c)     (myctype_[c] & CNTRL)



#endif
