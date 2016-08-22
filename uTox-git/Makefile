# $NetBSD$

DISTNAME=	uTox-0.9.5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=GrayHatter/}

GIT_REPOSITORIES=	uTox
GIT_REPO.uTox=	http://github.com/GrayHatter/uTox.git
WRKSRC=	${WRKDIR}/uTox

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://utox.org/
COMMENT=	Lightweight Tox client for the desktop
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../wip/toxcore/buildlink3.mk"
.include "../../wip/filter_audio/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
