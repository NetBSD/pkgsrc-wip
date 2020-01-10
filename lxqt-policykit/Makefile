# $NetBSD$

DISTNAME=	lxqt-policykit-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-policykit/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

EGDIR=			share/lxqt/lxqt-policykit-agent
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/lxqt
CONF_FILES=		${EGDIR}/xdg/autostart/lxqt-policykit-agent.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-policykit-agent.desktop

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	autostart/CMakeLists.txt
SUBST_SED.conf=		-e 's,$${LXQT_ETC_XDG_DIR}/,${EGDIR}/xdg/,'
SUBST_STAGE.conf=	pre-configure

INSTALLATION_DIRS+=	bin

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../wip/lxqt-build-tools

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../security/polkit-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
