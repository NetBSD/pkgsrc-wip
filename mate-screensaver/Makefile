# $NetBSD: Makefile,v 1.9 2015/04/10 12:20:36 krytarowski Exp $

DISTNAME=	mate-screensaver-1.12.0
CATEGORIES=	x11
MASTER_SITES=	http://pub.mate-desktop.org/releases/1.12/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mate-desktop.org/
COMMENT=	Screen saver and locker for the MATE desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

CONFLICTS+=	gnome-screensaver-[0-9]*

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	data/mate-screensaver.pc.in

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-console-kit=yes
CONFIGURE_ARGS+=	--with-systemd=no

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples/${PKGBASE}
INSTALL_MAKE_FLAGS+=	PAM_PREFIX=${PREFIX}/share/examples/pam.d

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/menus
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/autostart/mate-screensaver.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/mate-screensaver.desktop
CONF_FILES+=	${PREFIX}/share/examples/mate-screensaver/xdg/menus/mate-screensavers.menu \
		${PKG_SYSCONFDIR}/xdg/menus/mate-screensavers.menu

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		pam

.if ${OPSYS} != "Darwin"
DEPENDS+=		pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid
INSTALLATION_DIRS+=	${PREFIX}/share/examples/pam.d

post-extract:
	${CP} ${FILESDIR}/mate-screensaver.pam ${WRKDIR}

SUBST_CLASSES+=		pam-conf
SUBST_STAGE.pam-conf=	post-configure
SUBST_FILES.pam-conf=	${WRKDIR}/mate-screensaver.pam
SUBST_VARS.pam-conf=	PREFIX

PLIST.pam=		yes

post-install:
	${TEST} -f ${DESTDIR}${PREFIX}/share/examples/pam.d/mate-screensaver || \
		${INSTALL_DATA} ${WRKDIR}/mate-screensaver.pam ${DESTDIR}${PREFIX}/share/examples/pam.d/mate-screensaver

MAKE_DIRS+=	/etc/pam.d
CONF_FILES+=	${PREFIX}/share/examples/pam.d/mate-screensaver \
		/etc/pam.d/mate-screensaver

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	consolekit-[0-9]*:../../sysutils/consolekit
.endif

.include "../../devel/glib2/schemas.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/mate-desktop/buildlink3.mk"
.include "../../wip/mate-menus/buildlink3.mk"
.include "../../wip/libmatekbd/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXxf86misc/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
