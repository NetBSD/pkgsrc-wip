# $NetBSD$

DISTNAME=	lxqt-session-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-session/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Session manager
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin

EGDIR=			share/examples/lxqt-session
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart
CONFIG_FILES=		${EGDIR}/xdg/autostart/lxqt-xscreensaver-autostart.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-xscreensaver-autostart.desktop

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	autostart/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	pre-configure

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/etc/xdg/openbox/lxqt-rc.xml

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools
DEPENDS+=	xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
