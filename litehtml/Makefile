# $NetBSD$

DISTNAME=	litehtml-0.4.0.20170407
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=litehtml/}
GITHUB_TAG=	d7cc6abfe1141770718404aaf9b17db80ed3f196

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.litehtml.com/
COMMENT=	Fast and lightweight HTML/CSS rendering engine
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	include/litehtml/litehtml include/litehtml/src lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/litehtml.h ${DESTDIR}${PREFIX}/include/litehtml/litehtml
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include/litehtml/src
	${INSTALL_LIB} ${WRKSRC}/liblitehtml.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
