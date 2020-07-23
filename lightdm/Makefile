# $NetBSD: $

DISTNAME=	lightdm-1.30.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=canonical/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/canonical/lightdm
COMMENT=	Light cross-desktop display manager
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

PKG_COMPILER=		clang
PKG_CC=			clang
PKG_CXX=		clang

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LANGUAGES+=		c c++11
USE_PKGLOCALEDIR=	yes
BUILD_DEFS+=		PKG_SYSCONFBASE VARBASE

PKGCONFIG_OVERRIDE+=	liblightdm-gobject/liblightdm-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	liblightdm-qt/liblightdm-qt-2.pc.in

TOOL_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

LIGHTDM_GROUP=			lightdm
LIGHTDM_USER=			lightdm
PKG_GROUPS_VARS+=		LIGHTDM_GROUP
PKG_USERS_VARS+=		LIGHTDM_USER
PKG_GROUPS=			${LIGHTDM_GROUP}
PKG_USERS=			${LIGHTDM_USER}:${LIGHTDM_GROUP}
PKG_GECOS.${LIGHTDM_USER}=	Light Display Manager user
PKG_HOME.${LIGHTDM_USER}=	${VARBASE}/lib/lightdm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIGHTDM_MINVT=		1
.elif ${OPSYS} == "FreeBSD"
LIGHTDM_MINVT=		9
.else
LIGHTDM_MINVT=		7
.endif

PKG_SYSCONFSUBDIR=	lightdm
EGDIR=			${PREFIX}/share/examples/lightdm
INSTALLATION_DIRS+=	${EGDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	${EGDIR}/pam.d
CONF_FILES+=		${EGDIR}/lightdm.conf ${PKG_SYSCONFDIR}/lightdm.conf
CONF_FILES+=		${EGDIR}/keys.conf ${PKG_SYSCONFDIR}/keys.conf
CONF_FILES+=		${EGDIR}/users.conf ${PKG_SYSCONFDIR}/users.conf
CONF_FILES_PERMS+=	${EGDIR}/Xsession ${PKG_SYSCONFDIR}/Xsession \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
CONF_FILES+=		${EGDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
CONF_FILES+=		${EGDIR}/pam.d/lightdm ${PKG_SYSCONFBASE}/pam.d/lightdm
CONF_FILES+=		${EGDIR}/pam.d/lightdm-autologin ${PKG_SYSCONFBASE}/pam.d/lightdm-autologin
CONF_FILES+=		${EGDIR}/pam.d/lightdm-greeter ${PKG_SYSCONFBASE}/pam.d/lightdm-greeter
MAKE_DIRS_PERMS+=	${VARBASE}/lib/lightdm ${LIGHTDM_USER} ${LIGHTDM_GROUP} 1770
MAKE_DIRS_PERMS+=	${VARBASE}/lib/lightdm-data ${LIGHTDM_USER} ${LIGHTDM_GROUP} 1770

SUBST_CLASSES+=		xsession
SUBST_STAGE.xsession=	pre-configure
SUBST_MESSAGE.xsession=	Fixing Xsession path.
SUBST_FILES.xsession=	data/Xsession
SUBST_VARS.xsession=	PKG_SYSCONFBASE PREFIX

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Adjustment of configuration file.
SUBST_FILES.conf=	data/lightdm.conf
SUBST_VARS.conf=	LIGHTDM_MINVT PREFIX

post-extract:
	${RUN}${CP} ${FILESDIR}/Xsession ${WRKSRC}/data/Xsession

pre-install:
	${INSTALL_DATA} ${WRKSRC}/data/lightdm.conf ${DESTDIR}${EGDIR}/lightdm.conf
	${INSTALL_DATA} ${WRKSRC}/data/keys.conf ${DESTDIR}${EGDIR}/keys.conf
	${INSTALL_DATA} ${WRKSRC}/data/users.conf ${DESTDIR}${EGDIR}/users.conf
	${INSTALL_DATA} ${WRKSRC}/data/org.freedesktop.DisplayManager.conf \
	  ${DESTDIR}${EGDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
	${INSTALL_DATA} ${WRKSRC}/data/pam/lightdm ${DESTDIR}${EGDIR}/pam.d/lightdm
	${INSTALL_DATA} ${WRKSRC}/data/pam/lightdm-autologin ${DESTDIR}${EGDIR}/pam.d/lightdm-autologin
	${INSTALL_DATA} ${WRKSRC}/data/pam/lightdm-greeter ${DESTDIR}${EGDIR}/pam.d/lightdm-greeter
	${INSTALL_DATA} ${WRKSRC}/data/Xsession ${DESTDIR}${EGDIR}/Xsession

post-install:
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFDIR}/lightdm.conf
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFDIR}/keys.conf
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFDIR}/users.conf
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/apparmor.d/abstractions/lightdm
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/apparmor.d/abstractions/lightdm_chromium-browser
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/apparmor.d/lightdm-guest-session
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/init/lightdm.conf
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/pam.d/lightdm
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/pam.d/lightdm-autologin
	${RUN}${RM} ${DESTDIR}${PKG_SYSCONFBASE}/pam.d/lightdm-greeter

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openpam/buildlink3.mk"
.include "../../sysutils/accountsservice/buildlink3.mk"
.include "../../sysutils/consolekit/buildlink3.mk"
.include "../../sysutils/upower/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
