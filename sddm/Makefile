# $NetBSD$

DISTNAME=	sddm-0.21.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sddm/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sddm/sddm
COMMENT=	QML based X11 and Wayland display manager
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	dbus-[0-9]*:../../sysutils/dbus
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

RCD_SCRIPTS+=	sddm

BUILD_DEFS+=	VARBASE

.if !exists(/etc/login.defs)
CMAKE_CONFIGURE_ARGS+=	-DUID_MIN=1000
CMAKE_CONFIGURE_ARGS+=	-DUID_MAX=65000
.endif
CMAKE_CONFIGURE_ARGS+=	-DDBUS_CONFIG_DIR=${PREFIX}/share/examples/sddm
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR:PATH=${PKG_SYSCONFDIR:Q}
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MAN_PAGES=ON
CMAKE_CONFIGURE_ARGS+=	-DRST2MAN_EXECUTABLE=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}

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

.include "options.mk"

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Fix hard-coded absolute paths.
SUBST_FILES.vars+=	src/common/Configuration.h
SUBST_FILES.vars+=	data/man/sddm.conf.rst.in
SUBST_VARS.vars=	PREFIX X11BASE

SDDM_GROUP=			sddm
SDDM_USER=			sddm
SDDM_HOME=			${VARBASE}/lib/sddm
PKG_GROUPS_VARS+=		SMDM_GROUP
PKG_USERS_VARS+=		SDDM_USER
PKG_GROUPS=			${SDDM_GROUP}
PKG_USERS=			${SDDM_USER}:${SDDM_GROUP}
PKG_GECOS.${SDDM_USER}=		SDDM user
PKG_HOME.${SDDM_USER}=		${SDDM_HOME}

OWN_DIRS_PERMS+=	${SDDM_HOME} ${SDDM_USER} ${SDDM_GROUP} 0770

post-install:
	${INSTALL_DIR} ${DESTDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${FILESDIR}/xsessions/*.desktop ${DESTDIR}${PREFIX}/share/xsessions
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${DESTDIR}${PREFIX}/share/sddm/scripts/xinit-session

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
