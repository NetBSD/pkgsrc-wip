# $NetBSD$

DISTNAME=	lxqt-runner-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-runner/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Launch applications quickly by typing commands
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

EGDIR=			share/examples/lxqt-runner
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart
CONF_FILES=		${EGDIR}/xdg/autostart/lxqt-runner.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-runner.desktop

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	autostart/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	pre-configure

INSTALLATION_DIRS+=	lib

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
