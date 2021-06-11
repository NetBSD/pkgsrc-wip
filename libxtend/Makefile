# $NetBSD$

DISTNAME=	libxtend-0.1.2.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	f6146a2f74b4b12648ff73119d50120ef1269dbc

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/libxtendc
COMMENT=	Miscellaneous functions to extend libc
LICENSE=	2-clause-bsd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == Darwin
BUILD_TARGET=	apple
INSTALL_TARGET=	apple-install
.else
INSTALL_TARGET=	install-strip
.endif

MAKE_ENV+=	DYLIB_PATH=${PREFIX}/lib

pre-build:
	cd ${WRKSRC} && ${MAKE} depend

.include "../../mk/bsd.pkg.mk"
