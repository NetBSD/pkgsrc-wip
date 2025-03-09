# $NetBSD$

DISTNAME=	fcitx5-cskk-1.2.0
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcitx/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-cskk
COMMENT=	SKK input method plugin for fcitx5 that uses LibCSKK
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

INSTALLATION_DIRS+=	lib/fcitx5
INSTALLATION_DIRS+=	share/fcitx5/addon share/fcitx5/cskk share/fcitx5/inputmethod
.for lang in de ja ko ru zh_CN zh_TW
INSTALLATION_DIRS+=	share/locale/${lang}/LC_MESSAGES
.endfor
INSTALLATION_DIRS+=	share/metainfo
.for size in 24x24 256x256 32x32 48x48
INSTALLATION_DIRS+=	share/icons/hicolor/${size}/apps
.endfor

CMAKE_CONFIGURE_ARGS+=	-DSKK_DICT_DEFAULT_PATH=${PREFIX}/share/skk/SKK-JISYO.L

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../wip/cskk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
