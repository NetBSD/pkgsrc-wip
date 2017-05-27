# $NetBSD: Makefile,v 1.1 2017/01/30 14:16:42 mef Exp $

# no Release yet
GIT_COMMIT=	fef89a4174a7bf8cd99fa9154864ce9e8e3bf989
DISTNAME=	master
PKGNAME=	crossguid-0.0_pre20160908
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=/graeme-hill/crossguid/archive/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/graeme-hill/crossguid
COMMENT=	C++ GUID library
LICENSE=	mit

WRKSRC=		${WRKDIR}/crossguid-master

USE_LANGUAGES=	c++11

INSTALLATION_DIRS+=	lib include

do-build:
	cd ${WRKSRC} && \
	${CXX} guid.cpp -DGUID_LIBUUID -fPIC -shared -o libcrossguid.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/guid.h ${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libcrossguid.so ${DESTDIR}${PREFIX}/lib

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
