/*===---- wmmintrin.h - AES intrinsics ------------------------------------===
#ifndef _WMMINTRIN_H
#define _WMMINTRIN_H

#include <emmintrin.h>

#if !defined (__AES__) && !defined (__PCLMUL__)
# error "AES/PCLMUL instructions not enabled"
#else

#ifdef __AES__
#include <__wmmintrin_aes.h>
#endif /* __AES__ */

#ifdef __PCLMUL__
#include <__wmmintrin_pclmul.h>
#endif /* __PCLMUL__ */

#endif /* __AES__ || __PCLMUL__ */
#endif /* _WMMINTRIN_H */

