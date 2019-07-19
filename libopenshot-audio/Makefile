# $NetBSD$

GITHUB_PROJECT=	libopenshot-audio
DISTNAME=	v0.1.8
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	wip.orig
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenShot/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/OpenShot/libopenshot-audio/
COMMENT=	Library for high-quality editing and playback of audio
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/libopenshot-audio-0.1.8
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
