# $NetBSD$

DISTNAME=	sddm-0.21.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sddm/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sddm/sddm
COMMENT=	QML based X11 and Wayland display manager
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.if !exists(/etc/login.defs)
CMAKE_CONFIGURE_ARGS+=	-DUID_MIN=1000
CMAKE_CONFIGURE_ARGS+=	-DUID_MAX=65000
.endif
CMAKE_CONFIGURE_ARGS+=	-DDBUS_CONFIG_DIR=${PREFIX}/share/examples/sddm
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR:PATH=${PKG_SYSCONFDIR:Q}
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MAN_PAGES=ON
CMAKE_CONFIGURE_ARGS+=	-DRST2MAN_EXECUTABLE=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JOURNALD=OFF
CMAKE_CONFIGURE_ARGS+=	-DNO_SYSTEMD=ON
.endif

.if ${OPSYS} == "NetBSD"
CMAKE_CONFIGURE_ARGS+=	-DSDDM_INITIAL_VT=5
.endif

.if ${OPSYS} == "FreeBSD"
CMAKE_CONFIGURE_ARGS+=	-DSDDM_INITIAL_VT=7
.endif

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Fix hard-coded absolute paths.
SUBST_FILES.vars+=	src/common/Configuration.h
SUBST_FILES.vars+=	data/man/sddm.conf.rst.in
SUBST_VARS.vars=	PREFIX X11BASE

BUILD_DEFS+=		VARBASE
SDDM_GROUP=		sddm
SDDM_USER=		sddm
SDDM_HOME=		${VARBASE}/lib/sddm
PKG_GROUPS_VARS+=	SMDM_GROUP
PKG_USERS_VARS+=	SDDM_USER
PKG_GROUPS=		${SDDM_GROUP}
PKG_USERS=		${SDDM_USER}:${SDDM_GROUP}
PKG_GECOS.${SDDM_USER}=	SDDM user
PKG_HOME.${SDDM_USER}=	${SDDM_HOME}

OWN_DIRS_PERMS+=	${SDDM_HOME} ${SDDM_USER} ${SDDM_GROUP} 0770

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
RCD_SCRIPTS+=	sddm
.endif

INSTALLATION_DIRS+=	share/xsessions

post-install:
	${INSTALL_DATA} ${FILESDIR}/xsessions/*.desktop ${DESTDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${DESTDIR}${PREFIX}/share/sddm/scripts/xinit-session

PYTHON_FOR_BUILD_ONLY=  yes
.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
