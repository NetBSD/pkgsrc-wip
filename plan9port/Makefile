# $NetBSD$

DISTNAME=	plan9port-20180205
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=9fans/}
GITHUB_TAG=	4798a8a5560552480efde5fe8b1f7963a25a96d3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://9fans.github.io/plan9port/
COMMENT=	Plan 9 from User Space
LICENSE=	lucent

USE_LANGUAGES=	c c++

do-build:
	cd ${WRKSRC} && ./INSTALL -b

do-install:
	cd ${WRKSRC} && ./INSTALL -c

.include "../../fonts/fontconfig/buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
