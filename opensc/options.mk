# $NetBSD: options.mk,v 1.3 2008/08/07 19:03:31 htepper Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc
PKG_SUPPORTED_OPTIONS=	nsplugin openct pcsc-lite
PKG_SUGGESTED_OPTIONS=	nsplugin pcsc-lite
PLIST_VARS+=		nsplugin 

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnsplugin)
.include "../../security/libassuan/buildlink3.mk"
.include "../../security/pinentry/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-nsplugin
CONFIGURE_ARGS+=	--with-plugindir=/usr/pkg/lib/firefox/plugins
CONFIGURE_ARGS+=	--with-pinentry=/usr/pkg/bin/pinentry
PLIST.nsplugin=		yes
.else
CONFIGURE_ARGS+=	--disable-nsplugin
.endif

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcsc
.else
CONFIGURE_ARGS+=	--disable-pcsc
.endif

.if !empty(PKG_OPTIONS:Mopenct)
.include "../../wip/openct/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openct
.else
CONFIGURE_ARGS+=	--disable-openct
.endif
