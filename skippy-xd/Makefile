# $NetBSD$

DISTNAME=	skippy-xd-0.0.0.20150224
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=richardgv/}
GITHUB_TAG=	397216ca67074c71314f5e9a6e3f1710ccabc29e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/richardgv/skippy-xd
COMMENT=	Full-screen Exoise0styke standalone task switcher for X11
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	SKIPPYXD_VERSION=${GITHUB_TAG}
BUILD_TARGET=	skippy-xd

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
