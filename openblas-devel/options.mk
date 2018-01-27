PKG_OPTIONS_VAR=		PKG_OPTIONS.openblas
PKG_SUPPORTED_OPTIONS=		avx avx2 openmp interface64 dynamic_arch
PKG_SUGGESTED_OPTIONS=		dynamic_arch

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if empty(PKG_OPTIONS:Mavx)
BUILDFLAGS+=	NO_AVX=1
.endif

.if empty(PKG_OPTIONS:Mavx2)
BUILDFLAGS+=	NO_AVX2=1
.endif

.if ! empty(PKG_OPTIONS:Mopenmp)
BUILDFLAGS_THREAD+=	USE_OPENMP=1
CFLAGS+=		-fopenmp
CXXFLAGS+=		-fopenmp
FFLAGS+=		-fopenmp
BENCHMARK_THREADS_FLAG=	OMP_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.else
BUILDFLAGS_THREAD+=	NUM_THREADS=${MAXTHREADS} USE_THREAD=1
BENCHMARK_THREADS_FLAG=	OPENBLAS_NUM_THREADS=${BENCHMARK_MAXTHREADS}
.endif

BENCHMARK_MAXTHREADS?=	${MAXTHREADS}

.if ! empty(PKG_OPTIONS:Minterface64)
BUILDFLAGS+=	INTERFACE64=1
.endif

.if ! empty(PKG_OPTIONS:Mdynamic_arch)
# CPU-agnostic build
BUILDFLAGS+=	DYNAMIC_ARCH=1
.endif
