# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 14:39:01 keckhardt Exp $

DISTNAME=	lapack-3.4.0
PKGNAME=	lapack340-3.4.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=lapack/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage
LICENSE=	modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD=		4.6.0
USE_LANGUAGES=		c fortran
USE_LIBTOOL=		YES
BUILD_TARGET=		blaslib lapacklib
#BUILD_TARGET=		lapacklib

INSTALLATION_DIRS=	lib

FFLAGS=			-O2 -ffloat-store -mieee-fp
FFLAGSNOOPT=		-O0 -ffloat-store -mieee-fp

# With f2c-20090411nb4, libf2c-20090201nb3, we need EXT_ETIME but gcc44-4.4.1nb3
# needs INT_ETIME.  Rather than trying to enumerate all possible fortran
# compilers, just do a test for it.
do-configure:
	@${ECHO_N} "Checking if your fortran compiler has etime() as an intrinsic... "
	${FC} -o ${WRKDIR}/etime_test ${FILESDIR}/etime_test.f >${WRKDIR}/etime_test.log 2>&1; \
	if ${TEST} $$? -eq 0 ; then \
	${ECHO} "TIMER=INT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "YES" ; else \
	${ECHO} "TIMER=EXT_ETIME" >> ${WRKSRC}/make.inc ; ${ECHO} "NO" ; fi
	@${ECHO} "See ${WRKDIR}/etime_test.log for details on the test"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack340.la \
		${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/librefblas340.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
