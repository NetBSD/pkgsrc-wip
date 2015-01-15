# $NetBSD: options.mk,v 1.1 2015/01/15 11:27:56 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.consolekit
PKG_SUPPORTED_OPTIONS=	pam
PKG_SUGGESTED_OPTIONS=	pam

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	pam

.if !empty(PKG_OPTIONS:Mpam)
.include "../../mk/pam.buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pam-module
CONFIGURE_ARGS+=	--with-pam-module-dir=${PREFIX}/lib/security
PLIST.pam=	yes
.else
CONFIGURE_ARGS+=	--disable-pam-module
.endif
