# $NetBSD: options.mk,v 1.1 2013/05/02 20:02:42 fhajny Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.postgresql-pgpool
PKG_SUPPORTED_OPTIONS=	memcached pam ssl

.include "../../mk/bsd.options.mk"

###
### memcached support.
###
.if !empty(PKG_OPTIONS:Mmemcached)
CONFIGURE_ARGS+=	--with-memcached=${BUILDLINK_PREFIX.libmemcached}
.include "../../devel/libmemcached/buildlink3.mk"
.endif

###
### pam support.
###
.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.include "../../mk/pam.buildlink3.mk"
.endif

###
### OpenSSL support.
###
.if !empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--with-openssl
.include "../../security/openssl/buildlink3.mk"
.endif
