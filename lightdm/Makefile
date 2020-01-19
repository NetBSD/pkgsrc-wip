# $NetBSD: Makefile,v 1.8 2014/06/01 12:49:37 thomasklausner Exp $
#

DISTNAME=	lightdm-1.3.3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/lightdm/1.3/1.3.3/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/LightDM
COMMENT=	Light cross-desktop display manager
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests	# PAM
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool pkg-config
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
MAKE_ENV+=		"LIBLIGHTDM_GOBJECT_CFLAGS=-I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0/"

PKGCONFIG_OVERRIDE+=	liblightdm-gobject/liblightdm-gobject-1.pc.in
PKGCONFIG_OVERRIDE+=	liblightdm-qt/liblightdm-qt-2.pc.in

DEPENDS+=		itstool-[0-9]*:../../textproc/itstool

EGDIR=			${PREFIX}/share/examples
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/apparmor.d
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/dbus-1/system.d
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/lightdm ${PKG_SYSCONFDIR}/pam.d
INSTALLATION_DIRS+=	${EGDIR}/apparmor.d ${EGDIR}/dbus/system.d
INSTALLATION_DIRS+=	${EGDIR}/lightdm ${EGDIR}/pam.d
CONF_FILES+=		${EGDIR}/apparmor.d/lightdm-guest-session ${PKG_SYSCONFDIR}/apparmor.d/lightdm-guest-session
CONF_FILES+=		${EGDIR}/dbus/system.d/org.freedesktop.DisplayManager.conf ${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
CONF_FILES+=		${EGDIR}/lightdm/lightdm.conf ${PKG_SYSCONFDIR}/lightdm/lightdm.conf
CONF_FILES+=		${EGDIR}/lightdm/keys.conf ${PKG_SYSCONFDIR}/lightdm/keys.conf
CONF_FILES+=		${EGDIR}/lightdm/users.conf ${PKG_SYSCONFDIR}/lightdm/users.conf
CONF_FILES+=		${EGDIR}/pam.d/lightdm ${PKG_SYSCONFDIR}/pam.d/lightdm
CONF_FILES+=		${EGDIR}/pam.d/lightdm-autologin ${PKG_SYSCONFDIR}/pam.d/lightdm-autologin
CONF_FILES+=		${EGDIR}/pam.d/lightdm-greeter ${PKG_SYSCONFDIR}/pam.d/lightdm-greeter

pre-install:
	cd ${WRKSRC}/data && \
		${INSTALL_DATA} guest-session.apparmor ${DESTDIR}${EGDIR}/apparmor.d/lightdm-guest-session && \
		${INSTALL_DATA} org.freedesktop.DisplayManager.conf ${DESTDIR}${EGDIR}/dbus/system.d/org.freedesktop.DisplayManager.conf && \
		${INSTALL_DATA} lightdm.conf ${DESTDIR}${EGDIR}/lightdm/lightdm.conf && \
		${INSTALL_DATA} keys.conf ${DESTDIR}${EGDIR}/lightdm/keys.conf && \
		${INSTALL_DATA} users.conf ${DESTDIR}${EGDIR}/lightdm/users.conf;
	cd ${WRKSRC}/data/pam && \
		${INSTALL_DATA} lightdm ${DESTDIR}${EGDIR}/pam.d/lightdm && \
		${INSTALL_DATA} lightdm-autologin ${DESTDIR}${EGDIR}/pam.d/lightdm-autologin && \
		${INSTALL_DATA} lightdm-greeter ${DESTDIR}${EGDIR}/pam.d/lightdm-greeter

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/apparmor.d/lightdm-guest-session
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/dbus-1/system.d/org.freedesktop.DisplayManager.conf
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/init/lightdm.conf
	${RM} -rf ${DESTDIR}${PKG_SYSCONFDIR}/lightdm
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/pam.d/lightdm*

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../security/openpam/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxklavier+=	libxklavier>=4.0
.include "../../x11/libxklavier/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
