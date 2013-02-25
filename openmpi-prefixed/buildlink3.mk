# $NetBSD: buildlink3.mk,v 1.2 2013/02/25 16:17:32 outpaddling Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.6.3
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi-prefixed

MPI_PREFIX=	${PREFIX}/openmpi

# Setting compilers to something with ${PREFIX} in it causes pkgsrc to try
# to install a GCC package, which we don't want, since openmpi may be using
# a native compiler.  USE_NATIVE_GCC in mk.conf does not prevent this.
# Also, some packages such as fftw, use gcc for most compilations and mpicc
# only where necessary.
# CC=		${MPI_PREFIX}/bin/mpicc
# CXX=		${MPI_PREFIX}/bin/mpic++
# FC=		${MPI_PREFIX}/bin/mpif90
# F77=		${MPI_PREFIX}/bin/mpif77
# F90=		${MPI_PREFIX}/bin/mpif90

# Alternative: Set PATH so that the correct mpi compilers are found first.
PREPEND_PATH+=	${MPI_PREFIX}/bin

CFLAGS+=	-I${MPI_PREFIX}/include
LDFLAGS+=	-L${MPI_PREFIX}/lib

# Should we also set LD_LIBRARY_PATH and/or RPATH?
# CentOS:
# mpif77: error while loading shared libraries: libopen-pal.so.4: cannot open shared object file: No such file or directory

MAKE_ENV+=	LD_LIBRARY_PATH=${MPI_PREFIX}/lib

INSTALLATION_DIRS+=	${MPI_PREFIX}/bin ${MPI_PREFIX}/lib

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
