# $NetBSD$

GITHUB_PROJECT=	       telegramdesktop
DIST_SUBDIR=           tdesktop
TD_VERSION=            2.5.9
DISTNAME=              telegram-desktop-${TD_VERSION}
PKGREVISION=	       1
CATEGORIES=            chat
MASTER_SITES=          -https://github.com/${GITHUB_PROJECT}/${DIST_SUBDIR}/releases/download/v${TD_VERSION}/tdesktop-${TD_VERSION}-full.tar.gz
WRKSRC=                ${WRKDIR}/tdesktop-${TD_VERSION}-full

MAINTAINER=            jake.slazenger@yandex.com
HOMEPAGE=              https://desktop.telegram.org/
COMMENT=               Telegram Desktop messaging app
LICENSE=               gnu-gpl-v3

PKGSRC_COMPILER=       clang
ONLY_FOR_COMPILER=     clang

USE_LANGUAGES=         c c++ gnu++14
USE_CMAKE=             yes

#ONLY_FOR_COMPILER=     gcc
#GCC_REQD=              10

CMAKE_ARGS+=           -Ddisable_autoupdate=1
CMAKE_ARGS+=           -DCMAKE_INSTALL_PREFIX=${PREFIX}/usr/pkg
CMAKE_ARGS+=           -DCMAKE_BUILD_TYPE=Release
CMAKE_ARGS+=           -DTDESKTOP_API_TEST=ON
CMAKE_ARGS+=           -DDESKTOP_APP_USE_GLIBC_WRAPS=OFF
CMAKE_ARGS+=           -DDESKTOP_APP_USE_PACKAGED=ON 
CMAKE_ARGS+=           -DDESKTOP_APP_USE_PACKAGED_RLOTTIE=OFF
CMAKE_ARGS+=           -DDESKTOP_APP_DISABLE_CRASH_REPORTS=ON
CMAKE_ARGS+=           -DTDESKTOP_DISABLE_REGISTER_CUSTOM_SCHEME=ON
CMAKE_ARGS+=           -DTDESKTOP_DISABLE_DESKTOP_FILE_GENERATION=ON
CMAKE_ARGS+=           -DTDESKTOP_USE_PACKAGED_TGVOIP=OFF
CMAKE_ARGS+=           -DDESKTOP_APP_SPECIAL_TARGET=""
CMAKE_ARGS+=           -DTDESKTOP_LAUNCHER_BASENAME="telegram-desktop"
CMAKE_ARGS+=           -DDESKTOP_APP_DISABLE_WAYLAND_INTEGRATION=ON
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" # NetBSD-specific config
CMAKE_ARGS+=           -DTDESKTOP_WITHOUT_ALSA=ON
.elif ${OPSYS} == "Linux"
CMAKE_ARGS+=           -DTDESKTOP_WITHOUT_ALSA=OFF
.endif



.include "options.mk"

.include "../../archivers/minizip/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/range-v3/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtimageformats/buildlink3.mk"
.include "../../wip/rlottie/buildlink3.mk"
.include "../../wip/tg_owt-git/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
