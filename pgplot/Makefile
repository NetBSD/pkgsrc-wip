# $NetBSD: Makefile,v 1.1 2013/12/12 19:10:29 slitvinov Exp $

DISTNAME=	pgplot-${VER}
DISTFILES=	pgplot${VER}.tar.gz
VER=		5.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.astro.caltech.edu/pub/pgplot/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://www.astro.caltech.edu/~tjp/pgplot/
COMMENT=	Fortran and C graphics library
LICENSE=	pgplot-license
# http://www.astro.caltech.edu/~tjp/npgplot/license.html

# to build demos (see patches/patch-makemake)
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/pgplot
USE_LANGUAGES=	c fortran

# tested only for linux, try to replace s/linux/bsd
do-configure:
	cd ${WRKSRC} && \
	${SETENV}  ${CONFIGURE_ENV} ./makemake . linux g77_gcc

MAKE_FILE=		makefile
BUILD_MAKE_FLAGS=	FCOMPL=${PKG_FC} CCOMPL=${PKG_CC} FFLAGC='-O2 -g -fPIC'
# build cpgdemo to test the library
BUILD_TARGET=		all cpg cpgdemo

INSTALLATION_DIRS=	bin lib include
do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} pgxwin_server pgdisp ${DESTDIR}${PREFIX}/bin && \
	${INSTALL_LIB} libcpgplot.a libpgplot.a ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} grfont.dat rgb.txt ${DESTDIR}${PREFIX}/lib && \
	${INSTALL_DATA} cpgplot.h ${DESTDIR}${PREFIX}/include

.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
