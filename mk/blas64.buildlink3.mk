# $NetBSD: blas.buildlink3.mk,v 1.1 2020/10/12 21:51:57 bacon Exp $
#
# This Makefile fragment is meant to be included by packages that use any
# ILP64 BLAS (Basic Linear Algebra System with 64 bit indices) implementation
# instead of one particular one.
#
# Since pkgsrc always ships BLAS and LAPACK together (as upstream
# implementations do), this adds both BLAS_LIBS and LAPACK_LIBS to the linker
# flags.  Often, they will be identical or at least redundant. It is a matter
# of style to stay consistent in their use.
#
# Keywords: blas lapack netlib atlas openblas mkl
#
# === User-settable variables ===
#
# PKGSRC_BLAS_TYPES
#  This value specifies an exhaustive list of BLAS implementations we wish to
#  use in this pkgsrc installation, in descending order of preference.
#  The implementation selected for a build will be the first one in
#  PKGSRC_BLAS_TYPES that also appears in BLAS_ACCEPTED (see below).
#  Typically set in mk.conf.
#
#  Possible: one or more of netlib, openblas, openblas_pthread,
#    openblas_openmp, and maybe sometime Apple's accelerate.framework
#    (to come: Intel MKL, other external optimized builds)
#
#  Default: All currently supported implementations (${_BLAS_TYPES})
#
# === Package-settable variables ===
#
# BLAS_ACCEPTED
#   This is a list of blas packages that are compatible with the current
#   package. If not set, any BLAS implementation is OK.
#   Typically set in package Makefile.
#
# BLAS_C_INTERFACE
#   Set to yes if the package requires CBLAS or LAPACKE. This defines
#   BLAS_INCLUDES and pulls in additional packages for netlib. Optimized
#   implementations include the C interfaces in the main library anyway,
#   but you still have the effect on BLAS_INCLUDES.
#
# === Variables automatically set here for use in package builds ===
# 
# BLAS_TYPE
#   This is the BLAS implementation chosen for a particular package build from
#   PKGSRC_BLAS_TYPES and BLAS_ACCEPTED.  If PKGSRC_BLAS_TYPES and
#   BLAS_ACCEPTED have no implementations in common, it defaults to none
#   and the build fails.
# BLAS_LIBS
#   Linker flags used for linking to BLAS library
# LAPACK_LIBS
#   Linker flags used for linking to LAPACK library
# CBLAS_LIBS
#   Linker flags used for linking to CBLAS library
# LAPACKE_LIBS
#   Linker flags used for linking to LAPACKE library
# BLAS_INCLUDES
#   Preprocessor flags to locate/use C interfaces

.if defined(MK_BLAS_BUILDLINK3_MK)

PKG_FAIL_REASON+=	\
	"Attempt to mix 32 and 64 bit indices in BLAS for ${PKGNAME}."

.elif !defined(MK_BLAS_BUILDLINK3_MK)

MK_BLAS_BUILDLINK3_MK=

BUILD_DEFS+=		PKGSRC_BLAS_TYPES
BUILD_DEFS_EFFECTS+=	BLAS_TYPE BLAS_LIBS LAPACK_LIBS

.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices, in order of *DEFAULT* preference.
# netlib is the reference implementation to which all others conform and
# should come first by default for maximum compatibility.  It is also the
# slowest and not desirable in many situations.  Users can override by setting
# PKGSRC_BLAS_TYPES. (See comment above)
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
# TODO: Check if ILP64 is available from the framework
# Darwin
#.if exists(/System/Library/Frameworks/Accelerate.framework)
#_BLAS_TYPES+=	accelerate.framework
#.endif

BLAS_ACCEPTED?=	${_BLAS_TYPES}
PKGSRC_BLAS_TYPES?= ${_BLAS_TYPES}

_BLAS_MATCH=
.for b in ${PKGSRC_BLAS_TYPES}
_BLAS_MATCH+=	${BLAS_ACCEPTED:M${b}}
.endfor
.if !empty(_BLAS_MATCH)
BLAS_TYPE=	${_BLAS_MATCH:[1]}
.else
BLAS_TYPE=	none
.endif

.if ${BLAS_TYPE} == "netlib"
_BLAS_PKGPATH=		wip/lapack64
_CBLAS_PKGPATH=		wip/cblas64
_LAPACKE_PKGPATH=	wip/lapacke64
BLAS_LIBS=	-lblas64
LAPACK_LIBS=	-llapack64 ${BLAS_LIBS}
CBLAS_LIBS=	-lcblas64 ${BLAS_LIBS}
LAPACKE_LIBS=	-llapacke64 ${LAPACK_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/netlib64 -DWeirdNEC -DHAVE_LAPACK_CONFIG_H -DLAPACK_ILP64
.elif ${BLAS_TYPE} == "openblas"
_BLAS_PKGPATH=	wip/openblas64
BLAS_LIBS=	-lopenblas64
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas64
.elif ${BLAS_TYPE} == "openblas_pthread"
_BLAS_PKGPATH=	wip/openblas64_pthread
BLAS_LIBS=	-lopenblas64_pthread
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas64_pthread
.elif ${BLAS_TYPE} == "openblas64_openmp"
_BLAS_PKGPATH=	wip/openblas64_openmp
BLAS_LIBS=	-lopenblas64_openmp
LAPACK_LIBS=	${BLAS_LIBS}
CBLAS_LIBS=	${BLAS_LIBS}
LAPACKE_LIBS=	${BLAS_LIBS}
BLAS_INCLUDES=	-I${PREFIX}/include/openblas64_openmp
#.elif ${BLAS_TYPE} == "accelerate.framework"
#BLAS_LIBS=	-framework Accelerate
#LAPACK_LIBS=	${BLAS_LIBS}
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"There is no acceptable 64 bit BLAS for ${PKGNAME} in: ${PKGSRC_BLAS_TYPES}."
.endif

.if defined(_BLAS_PKGPATH)
.include "../../${_BLAS_PKGPATH}/buildlink3.mk"
.endif

.if !empty(BLAS_C_INTERFACE:Myes)
.  if defined(_CBLAS_PKGPATH)
.    include "../../${_CBLAS_PKGPATH}/buildlink3.mk"
.  endif
.  if defined(_LAPACKE_PKGPATH)
.    include "../../${_LAPACKE_PKGPATH}/buildlink3.mk"
.  endif
.else
.  undef	BLAS_INCLUDES
.endif

.endif # BLAS_BUILDLINK3_MK
