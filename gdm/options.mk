# $NetBSD$

PKG_OPTIONS_VAR=                PKG_OPTIONS.gdm
PKG_SUPPORTED_OPTIONS=          gdm-login
.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

PLIST_VARS+=	gnome-login

###
### gdm-login
### enables the daemon and gui greeter (experimental)
###
.if !empty(PKG_OPTIONS:Mgdm-login)
BUILD_DEFS+=	PKG_SYSCONFBASE VARBASE

OWN_DIRS=		${PKG_SYSCONFDIR}/Init
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostLogin
OWN_DIRS+=		${PKG_SYSCONFDIR}/PostSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/PreSession
OWN_DIRS+=		${PKG_SYSCONFDIR}/dm
OWN_DIRS+=		${PKG_SYSCONFDIR}/modules
OWN_DIRS+=		${VARBASE}/lib/gdm
OWN_DIRS+=		${VARBASE}/log/gdm

PKG_SYSCONFSUBDIR=	gdm
EGDIR=			${PREFIX}/share/examples/gdm
CONF_FILES=		${EGDIR}/custom.conf ${PKG_SYSCONFDIR}/custom.conf
CONF_FILES+=		${EGDIR}/Xsession ${PKG_SYSCONFDIR}/Xsession
CONF_FILES+=		${PREFIX}/share/examples/dbus-1/system.d/gdm.conf ${PKG_SYSCONFBASE}/dbus-1/system.d/gdm.conf

RCD_SCRIPTS=		gdm


INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/gdm/BuiltInSessions
INSTALLATION_DIRS+=	share/examples/pam.d

post-install:
	${INSTALL_DATA} ${FILESDIR}/NetBSD.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${FILESDIR}/custom.desktop \
		${DESTDIR}${PREFIX}/share/gdm/BuiltInSessions
	${INSTALL_DATA} ${FILESDIR}/gdm-* ${DESTDIR}/${PREFIX}/share/examples/pam.d
	${CHMOD} +x ${DESTDIR}${PREFIX}/share/examples/gdm/Xsession

PLIST.gdm-login=	yes
.else
# only install libgdm, without the daemon and login screen
INSTALLATION_DIRS+=	include/gdm
INSTALLATION_DIRS+=	lib/girepository-1.0
INSTALLATION_DIRS+=	lib/
INSTALLATION_DIRS+=	lib/pkgconfig
INSTALLATION_DIRS+=	share/gir-1.0 share/glib-2.0/schemas

INSTALL_DIRS=	# disable meson install

do-install:
	${INSTALL} ${WRKSRC}/output/libgdm/gdm-client-glue.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL} ${WRKSRC}/libgdm/gdm-client.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL} ${WRKSRC}/libgdm/gdm-sessions.h \
		${DESTDIR}${PREFIX}/include/gdm
	${INSTALL} ${WRKSRC}/libgdm/gdm-user-switching.h \
		${DESTDIR}${PREFIX}/include/gdm

	${INSTALL} ${WRKSRC}/output/libgdm/Gdm-1.0.typelib \
		${DESTDIR}${PREFIX}/lib/girepository-1.0
	${INSTALL} ${WRKSRC}/output/libgdm/libgdm.so \
		${DESTDIR}${PREFIX}/lib
	${INSTALL} ${WRKSRC}/output/libgdm/libgdm.so.1 \
		${DESTDIR}${PREFIX}/lib
	${INSTALL} ${WRKSRC}/output/libgdm/libgdm.so.1.0.0 \
		${DESTDIR}${PREFIX}/lib

	${INSTALL} ${WRKSRC}/output/meson-private/gdm.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

	${INSTALL} ${WRKSRC}/output/libgdm/Gdm-1.0.gir \
		${DESTDIR}${PREFIX}/share/gir-1.0
	${INSTALL} ${WRKSRC}/data/org.gnome.login-screen.gschema.xml \
		${DESTDIR}${PREFIX}/share/glib-2.0/schemas

BUILDLINK_DEPMETHOD.openpam=	build
.endif
