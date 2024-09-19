# $NetBSD$

GITHUB_PROJECT=	pulseaudio-qt
GITHUB_TAG=	v1.2.0
DISTNAME=	v1.2.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDE/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/KDE/pulseaudio-qt/
COMMENT=	Qt bindings for libpulse
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/pulseaudio-qt-1.2.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.pulseaudio+=      pulseaudio>=13.0
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
