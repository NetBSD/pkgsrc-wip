# $NetBSD: Makefile,v 1.6 2013/03/14 21:36:13 asau Exp $

DISTNAME=	libexecinfo-1.1
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	devel
MASTER_SITES=	$(MASTER_SITE_FREEBSD)

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=       http://www.freebsdsoftware.org/devel/libexecinfo.html
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

MAKE_FLAGS=	INCSDIR=${PREFIX}/include
MAKE_FLAGS+=	INCSYMLINKS=no
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib
MAKE_FLAGS+=	MKLINT=no
MAKE_FLAGS+=	SHLIBDIR=${PREFIX}/lib

CFLAGS.Linux+=	-D_GNU_SOURCE # Dl_info internals
CFLAGS.Linux+=	-Wno-unused-result # write(2) is declared specially

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libexecinfo.* ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libexecinfo_pic.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/execinfo.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
