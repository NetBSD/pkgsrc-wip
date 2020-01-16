# $NetBSD$

DISTNAME=	lxqt-config-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-config/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	System configuration (control center)
HOMEPAGE=	https://downloads.lxqt.org/
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DWITH_INPUT=OFF

EGDIR=			share/examples/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/menus
CONF_FILES=		${EGDIR}/xdg/menus/lxqt-config.menu \
			${PKG_SYSCONFDIR}/menus/lxqt-config.menu

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	pre-configure

INSTALLATION_DIRS+=	bin lib

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools
DEPENDS+=	lxqt-themes-[0-9]*:../../wip/lxqt-themes

.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
