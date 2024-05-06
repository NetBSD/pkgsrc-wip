# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.dillo
PKG_SUPPORTED_OPTIONS=	inet6 tls
PKG_SUGGESTED_OPTIONS=	inet6 tls

.include "../../mk/bsd.options.mk"

# Support for IPv6 protocol
.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

# Support for Transport Layer Security (TLS)
.if !empty(PKG_OPTIONS:Mtls)
CONFIGURE_ARGS+=	--enable-tls
CONFIGURE_ARGS+=	--disable-mbedtls
CONFIGURE_ARGS+=	--enable-openssl
CONFIGURE_ARGS+=	--with-ca-certs-dir=${SSLCERTS}
LIBS+=			-lssl
.include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tls
CONFIGURE_ARGS+=	--disable-mbedtls
CONFIGURE_ARGS+=	--disable-openssl
.endif
