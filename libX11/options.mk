# $NetBSD: options.mk,v 1.4 2007/01/23 06:23:37 bsadewitz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.libX11

PKG_OPTIONS_OPTIONAL_GROUPS=	threads
PKG_OPTIONS_GROUP.threads=	xcb
PKG_SUPPORTED_OPTIONS+=		loadable-i18n secure-rpc

CHECK_BUILTIN.pthread:=		yes

.include "../../mk/pthread.builtin.mk"
.  if !empty(USE_BUILTIN.pthread)
  PKG_OPTIONS_GROUP.threads+=		pthread
  PKG_SUGGESTED_OPTIONS=		pthread
.endif

CHECK_BUILTIN.pthread:=		no

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mxcb)
. include "../../wip/libxcb/buildlink3.mk"
  CONFIGURE_ARGS+=			--with-xcb
  PLIST_SRC+=				PLIST.xcb
  PKGCONFIG_OVERRIDE+=			x11-xcb.pc
. else
  CONFIGURE_ARGS+=			--without-xcb
.endif

.if !empty(PKG_OPTIONS:Mpthread)
  PTHREAD_AUTO_VARS=			yes
. include "../../mk/pthread.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mloadable-i18n)
  CONFIGURE_ARGS+=			--enable-loadable-i18n
  PLIST_SRC+=				PLIST.i18n
. include "../../mk/dlopen.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONSMsecure-rpc)
  CONFIGURE_ARGS+=			--enable-secure-rpc
.endif
