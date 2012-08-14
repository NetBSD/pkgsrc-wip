# $NetBSD: Makefile,v 1.3 2012/08/14 11:02:54 thomasklausner Exp $
#

DISTNAME=	libexecinfo-1.1
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles

MAINTAINER=	ober@NetBSD.org
HOMEPAGE=       http://www.freebsdsoftware.org/devel/libexecinfo.html
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

MAKE_FLAGS=	INCSDIR=${PREFIX}/include
MAKE_FLAGS+=	INCSYMLINKS=no
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib
MAKE_FLAGS+=	MKLINT=no
MAKE_FLAGS+=	SHLIBDIR=${PREFIX}/lib

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	include lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libexecinfo.* ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libexecinfo_pic.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/execinfo.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
