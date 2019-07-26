# $NetBSD$
#
# This Makefile fragment is meant to be included by packages that use any BLAS
# (Basic Linear Algebra System) implementation instead of one particular one.
#
# Since pkgsrc always ships BLAS and LAPACK together (as upstream
# implementations do), this sets both BLAS_LIBS to the linker flags needed to
# pull in the BLAS library and LAPACK_LIBS to the flags for the LAPACK library.
# Often, they will be identical or at least redundant. It is a matter
# of style to stay consistent in their use.
#
# Keywords: blas lapack atlas openblas mkl

# TODO: Also set a variable to find a matching pkg-config file
# to avoid duplicating its contents in BLAS_LIBS?
#
# === User-settable variables ===
#
# PKGSRC_BLAS_TYPES
#  This value specifies an exhaustive list of BLAS implementations
#  we wish to use on the system, in descending order of preference.
#  The implementation selected for a build will be the first one in
#  PKGSRC_BLAS_TYPES that also appears in BLAS_ACCEPTED (see below).
#  Typically set in mk.conf.
#
#  Possible: one or more of netlib, openblas, openblas_pthread,
#    openblas_openmp, and accelerate.framework
#    (to come: Intel MKL, other external optimized builds)
#
#  TODO: Should this be all currently supported implementations rather than
#        just netlib?  Otherwise, builds will fail with BLAS_ACCEPTED does
#        not include netlib.
#  Default: netlib
#
# === Package-settable variables ===
#
# BLAS_ACCEPTED
#   This is a list of blas packages that are compatible with the current
#   package. If not set, any package is OK.
#   Typically set in package Makefile.
#
# === Variables automatically set here for use in package builds ===
# 
# BLAS_TYPE
#   This is the BLAS implemtation chosen for a particular package build from
#   PKGSRC_BLAS_TYPES and BLAS_ACCEPTED.  If PKGSRC_BLAS_TYPES and
#   BLAS_ACCEPTED have no implementations in common, it defaults to none.
# BLAS_LIBS
#   Linker flags used for linking to BLAS library
# LAPACK_LIBS
#   Linker flags used for linking to LAPACK library

BUILD_DEFS+=		PKGSRC_BLAS_TYPES
BUILD_DEFS_EFFECTS+=	BLAS_TYPE BLAS_LIBS LAPACK_LIBS

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK=

# Upon commit change to: .include "bsd.prefs.mk"
.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices.
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
# Darwin
.if exists(/System/Library/Frameworks/Accelerate.framework)
_BLAS_TYPES+=	accelerate.framework
.endif

BLAS_ACCEPTED?=	${_BLAS_TYPES}
#  TODO: Should this be all currently supported implementations?
#        See User-settable variables above.
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
_BLAS_PKGPATH=	wip/lapack
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack ${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas"
_BLAS_PKGPATH=	wip/openblas
BLAS_LIBS=	-lopenblas
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_pthread"
_BLAS_PKGPATH=	wip/openblas_pthread
BLAS_LIBS=	-lopenblas_pthread
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "openblas_openmp"
_BLAS_PKGPATH=	wip/openblas_openmp
BLAS_LIBS=	-lopenblas_openmp
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${BLAS_TYPE} == "accelerate.framework"
BLAS_LIBS=	-framework Accelerate
LAPACK_LIBS=	${BLAS_LIBS}
# TODO: Add atlas
# TODO: Add external BLAS (other OpenBLAS/ATLAS, Intel MKL)
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"There is no acceptable BLAS for ${PKGNAME} in: ${PKGSRC_BLAS_TYPES}."
.endif

.if defined(_BLAS_PKGPATH)
.include "../../${_BLAS_PKGPATH}/buildlink3.mk"
.endif

.endif # BLAS_BUILDLINK3_MK
