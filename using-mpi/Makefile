# $NetBSD: Makefile,v 1.5 2012/10/07 17:41:40 asau Exp $

DISTNAME=	UsingMPI
PKGNAME=	UsingMPI-2
CATEGORIES=	parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/using/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www-unix.mcs.anl.gov/mpi/learning.html
COMMENT=	Sample programs from "Using MPI" (2nd ed.) book

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c fortran77 c++
CONFIGURE_ARGS+=	--with-mpich=${PREFIX}/bin
BUILD_MAKE_FLAGS+=	CXX=${PREFIX}/bin/mpicxx
BUILD_MAKE_FLAGS+=	LIBS=-lm

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/advmsg/nbodypipe ${DESTDIR}${PREFIX}/bin/nbodypipe
	${INSTALL_PROGRAM} ${WRKSRC}/intermediate/oned ${DESTDIR}${PREFIX}/bin/oned
	${INSTALL_PROGRAM} ${WRKSRC}/intermediate/twod ${DESTDIR}${PREFIX}/bin/twod
	${INSTALL_PROGRAM} ${WRKSRC}/libraries/ibcast-test ${DESTDIR}${PREFIX}/bin/ibcast-test
.for _prog_ in pi3 cpi pi pit matvec matmat matmatlog monte
	${INSTALL_PROGRAM} ${WRKSRC}/simplempi/${_prog_} ${DESTDIR}${PREFIX}/bin/${_prog_}
.endfor

.include "../../mk/mpi.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
