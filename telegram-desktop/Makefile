# $NetBSD$

GITHUB_PROJECT=		tdesktop
GITHUB_RELEASE=		v${TD_VERSION}
DIST_SUBDIR=		tdesktop
TD_VERSION=		7.1.3
DISTNAME=		tdesktop-${TD_VERSION}-full
PKGNAME=		telegram-desktop-${TD_VERSION}
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_GITHUB:=telegramdesktop/}

MAINTAINER=		jake.slazenger@yandex.com
HOMEPAGE=		https://desktop.telegram.org/
COMMENT=		Telegram Desktop messaging app
LICENSE=		gnu-gpl-v3

USE_LANGUAGES=		c c++ gnu++20
USE_TOOLS+=		pkg-config perl gdbus-codegen

ONLY_FOR_COMPILER=	gcc
GCC_REQD+=		14

INSTALL_UNSTRIPPED=	yes
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=RelWithDebInfo
CMAKE_CONFIGURE_ARGS+=	-DTDESKTOP_API_TEST=ON
CMAKE_CONFIGURE_ARGS+=	-DDESKTOP_APP_USE_PACKAGED=ON
CMAKE_CONFIGURE_ARGS+=	-DDESKTOP_APP_DISABLE_CRASH_REPORTS=ON
CMAKE_CONFIGURE_ARGS+=	-DDESKTOP_APP_DISABLE_AUTOUPDATE=ON
CMAKE_CONFIGURE_ARGS+=	-DLINUX=ON

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../comms/srtp/buildlink3.mk"
.include "../../misc/rhash/buildlink3.mk"
.include "../../archivers/minizip/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/rnnoise/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/range-v3/buildlink3.mk"
.include "../../devel/xxhash/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../wip/ada-url/buildlink3.mk"
.include "../../wip/rlottie/buildlink3.mk"
.include "../../wip/tde2e/buildlink3.mk"
.include "../../wip/tg_owt-git/buildlink3.mk"
.include "../../wip/libyuv-git/buildlink3.mk"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../security/libfido2/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
