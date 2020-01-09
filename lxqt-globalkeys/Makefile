# $NetBSD$

DISTNAME=	lxqt-globalkeys-0.14.3
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-globalkeys/0.14.3/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Daemon and library for global keyboard shortcuts registration
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

EGDIR=			share/examples/lxqt-globalkeys
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart
CONF_FILES=		${EGDIR}/xdg/autostart/lxqt-globalkeyshortcuts.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-globalkeyshortcuts.desktop

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	autostart/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	pre-configure

INSTALLATION_DIRS+=	bin lib

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
