# $NetBSD: options.mk,v 1.1.1.1 2008/03/27 18:54:57 rootcho Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.nginx
PKG_SUPPORTED_OPTIONS=	ssl pcre
PKG_SUGGESTED_OPTIONS=	ssl pcre

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mail_ssl_module
.endif

.if !empty(PKG_OPTIONS:Mpcre)
.include "../../devel/pcre/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-pcre
CONFIGURE_ARGS+=	--without-http_rewrite_module
.endif
