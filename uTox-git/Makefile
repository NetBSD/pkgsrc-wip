# $NetBSD$

DISTNAME=	uTox-0.16.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=uTox/}

GIT_REPOSITORIES=	uTox
GIT_REPO.uTox=		http://github.com/uTox/uTox.git
GIT_BRANCH.uTox=	develop
WRKSRC=			${WRKDIR}/uTox

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://utox.org/
COMMENT=	Lightweight Tox client for the desktop
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
TEST_TARGET=	test

# Unclear crash in OpenAL on NetBSD
CMAKE_ARGS+=	-DENABLE_ASAN=OFF

.include "../../chat/toxcore/buildlink3.mk"
.include "../../audio/filter_audio/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../graphics/libv4l/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../devel/check/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
