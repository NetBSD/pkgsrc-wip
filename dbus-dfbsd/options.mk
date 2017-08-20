# $NetBSD: options.mk,v 1.11 2017/03/14 15:34:56 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dbus
PKG_SUPPORTED_OPTIONS+=	debug x11 enable-in-rcvar nonroot
PKG_SUGGESTED_OPTIONS=	x11

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PKG_SUGGESTED_OPTIONS+= enable-in-rcvar	
.endif

.if (${OPSYS} == "NetBSD"  ||	\
     ${OPSYS} == "FreeBSD" ||	\
     ${OPSYS} == "OpenBSD" ||	\
     ${OPSYS} == "Darwin" ||	\
     ${OPSYS} == "DragonFly")
PKG_SUPPORTED_OPTIONS+=	kqueue
PKG_SUGGESTED_OPTIONS+=	kqueue
.endif

# We may want to make it SUGGESTED once we have a framework for
# launchd support. See PR/49591.
PKG_SUPPORTED_OPTIONS.Darwin+=	launchd

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-asserts
CONFIGURE_ARGS+=	--enable-verbose-mode
.else
CONFIGURE_ARGS+=	--disable-asserts
CONFIGURE_ARGS+=	--disable-verbose-mode
.endif

.if !empty(PKG_OPTIONS:Mkqueue)
CONFIGURE_ARGS+= 	--enable-kqueue
.else
CONFIGURE_ARGS+=	--disable-kqueue
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
.  include "../../x11/libX11/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt=	build
.  include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if !empty(PKG_OPTIONS:Mlaunchd)
MESSAGE_SRC+=			MESSAGE.launchd
PLIST.launchd=			yes
CONFIGURE_ARGS+=		--enable-launchd
CONFIGURE_ARGS+=		--with-launchd-agent-dir=${PREFIX}/Library/LaunchAgents
.else
CONFIGURE_ARGS+=		--disable-launchd
.endif

.if !empty(PKG_OPTIONS:Menable-in-rcvar)
DBUS_RCVAR=		dbus_enable
.else
DBUS_RCVAR=		dbus
.endif

.if !empty(PKG_OPTIONS:Mnonroot)
OWN_DIRS_PERMS+=	${VARBASE}/db/dbus ${DBUS_USER} ${DBUS_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4511
FILES_SUBST+=		DBUS_VAR_RUN_USER_SH=${DBUS_USER}
FILES_SUBST+=		DBUS_VAR_RUN_GROUP_SH=${DBUS_GROUP}
.else
OWN_DIRS_PERMS+=	${VARBASE}/db/dbus ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
SPECIAL_PERMS+=		libexec/dbus-daemon-launch-helper ${REAL_ROOT_USER} ${DBUS_GROUP} 4750
FILES_SUBST+=		DBUS_VAR_RUN_USER_SH=${REAL_ROOT_USER}
FILES_SUBST+=		DBUS_VAR_RUN_GROUP_SH=${REAL_ROOT_GROUP}
.endif

FILES_SUBST+=		DBUS_RCVAR=${DBUS_RCVAR}
