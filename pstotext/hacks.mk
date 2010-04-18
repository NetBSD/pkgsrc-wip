# $NetBSD: hacks.mk,v 1.1 2010/04/18 19:22:45 schaecsn Exp $

.if !defined(PSTOTEXT_HACKS_MK)
PSTOTEXT_HACKS_MK=   defined

.include "../../mk/compiler.mk"

###
### With debian's security patch patch-ab, pstotext miscompiles under several
### versions of gcc-4.x when -O2 is used (verified under linux and freebsd).
### For the time being, pstotext will be optimized on every platform with -O1
### when a version of gcc-4 is used.
###
.if !empty(CC_VERSION:Mgcc-4.*)
PKG_HACKS+=             optimisation
BUILD_MAKE_FLAGS+=	CFLAGS=-O
.endif

.endif  # PSTOTEXT_HACKS_MK
