# $NetBSD$
#
# This Makefile fragment is meant to be included by packages
# that use any BLAS implementation instead of one particular one.
#
# Since we always ship BLAS and LAPACK together (as upstream variants
# do), this sets both BLAS_LIBS to the linker flags needed to pull in
# the BLAS library and LAPACK_LIBS to the flags for the LAPACK library.
# Often, they will be identical or at least redundant. It is a matter
# of style to stay consistent in their use.

# TODO: Also set a variable to find a matching pkg-config file
# to avoid duplicating its contents in BLAS_LIBS?
#
# === User-settable variables ===
#
# PKGSRC_BLAS_PREFERRED
#  This value specifies an exhaustive list of BLAS implementations
#  we wish to use on the system, in descending order of preference.
#
#  Possible: one or more of netlib, openblas, openblas_pthread,
#    openblas_openmp, and accelerate.framework
#    (to come: Intel MKL, other external optimized builds)
#
#  Default: netlib
#
# === Per-package variables ===
#
# BLAS_ACCEPTED
#   This is a list of blas packages that are compatible with the current
#   package. If not set, any package is OK.
#
# === Variables for package Makefiles to use ===
# 
# BLAS_TYPE
#   This is the finally selected type of BLAS from BLAS_PREFERRED or none.
# BLAS_LIBS
#   linker flags to use for linking to BLAS library
# LAPACK_LIBS
#   linker flags to use for linking to LAPACK library

BUILD_DEFS+=	PKGSRC_BLAS_PREFERRED
BUILD_DEFS_EFFECTS+=	BLAS_TYPE BLAS_LIBS LAPACK_LIBS

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK=

.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices.
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
.if exists(/System/Library/Frameworks/Accelerate.framework)
_BLAS_TYPES+=	accelerate.framework
.endif

BLAS_ACCEPTED?=	${_BLAS_TYPES}
PKGSRC_BLAS_PREFERRED?= netlib openblas

_BLAS_MATCH=
.for b in ${PKGSRC_BLAS_PREFERRED}
_BLAS_MATCH+=	${BLAS_ACCEPTED:M${b}}
.endfor
.if(!empty(_BLAS_MATCH))
BLAS_TYPE=	${_BLAS_MATCH:[1]}
.else
BLAS_TYPE=	none
.endif

.if ${BLAS_TYPE} == "netlib"
_BLAS_PACKAGE=	wip/lapack
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack ${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas"
_BLAS_PACKAGE=	wip/openblas
BLAS_LIBS=	-lopenblas
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_pthread"
_BLAS_PACKAGE=	wip/openblas_pthread
BLAS_LIBS=	-lopenblas_pthread
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_openmp"
_BLAS_PACKAGE=	wip/openblas_openmp
BLAS_LIBS=	-lopenblas_openmp
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "accelerate.framework"
BLAS_LIBS=	-framework Accelerate
LAPACK_LIBS=	${BLAS_LIBS}
# TODO: atlas
# TODO: external BLAS (other OpenBLAS/ATLAS, Intel MKL)
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"There is no acceptable BLAS for ${PKGNAME} in: ${PKGSRC_BLAS_PREFERRED}."
.endif

.if defined(_BLAS_PACKAGE)
.include "../../${_BLAS_PACKAGE}/buildlink3.mk"
.endif

.endif # BLAS_BUILDLINK3_MK
