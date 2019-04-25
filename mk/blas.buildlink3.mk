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
# BLAS_TYPE
#	This value represents the type of BLAS we wish to use on the system.
#
#	Possible: netlib, openblas, openblas_pthread, openblas_openmp
#	Default: netlib
#
# === Per-package variables ===
#
# BLAS_ACCEPTED
#       This is a list of blas packages that are compatible with the current
#       package. If not set, any package is OK.

.if !defined(BLAS_BUILDLINK3_MK)
BLAS_BUILDLINK3_MK=	# define it

.include "../../mk/bsd.prefs.mk"

# List of all possible BLAS choices.
_BLAS_TYPES=	netlib openblas openblas_pthread openblas_openmp
# Add Accelerate framework on Darwin (pulled from math/R).
.if exists(/System/Library/Frameworks/Accelerate.framework)
_BLAS_TYPES+=	accelerate.framework
.endif
# Currently chosen type.
# Default is the standard, slow, easily available.
BLAS_TYPE?=	netlib
BLAS_LIBS=
BLAS_ACCEPTED?= ${_BLAS_TYPES}

.  if !empty(BLAS_ACCEPTED:M${BLAS_TYPE})
_BLAS_TYPE=     ${BLAS_TYPE}
.  else
_BLAS_TYPE=     none
.  endif

.if ${_BLAS_TYPE} == "netlib"
_BLAS_PACKAGE=	wip/lapack
BLAS_LIBS=	-lblas
LAPACK_LIBS=	-llapack ${BLAS_LIBS}
.elif ${_BLAS_TYPE} == "openblas"
_BLAS_PACKAGE=	wip/openblas
BLAS_LIBS=	-lopenblas
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${_BLAS_TYPE} == "openblas_pthread"
_BLAS_PACKAGE=	wip/openblas_pthread
BLAS_LIBS=	-lopenblas_pthread
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${_BLAS_TYPE} == "openblas_openmp"
_BLAS_PACKAGE=	wip/openblas_openmp
BLAS_LIBS=	-lopenblas_openmp
LAPACK_LIBS=	${BLAS_LIBS}
.elif ${_BLAS_TYPE} == "accelerate.framework"
BLAS_LIBS=	-framework Accelerate
LAPACK_LIBS=	${BLAS_LIBS}
# TODO: atlas
# TODO: external BLAS (other OpenBLAS/ATLAS, Intel MKL)
.else # invalid or unimplemented type
PKG_FAIL_REASON+=	\
	"${BLAS_TYPE} is not an acceptable BLAS type for ${PKGNAME}."
.endif

.if defined(_BLAS_PACKAGE)
.include "../../${_BLAS_PACKAGE}/buildlink3.mk"
.endif

.endif	# BLAS_BUILDLINK3_MK
