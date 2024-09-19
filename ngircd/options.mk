# $NetBSD$
PKG_OPTIONS_VAR=		PKG_OPTIONS.ngircd
PKG_SUPPORTED_OPTIONS=		zlib tcpwrappers ident pam iconv inet6 ngircd-sniffer ngircd-irc+ ngircd-strictrfc
PKG_OPTIONS_OPTIONAL_GROUPS=	ssl
PKG_OPTIONS_GROUP.ssl=		gnutls openssl
PKG_SUGGESTED_OPTIONS=		zlib ident inet6 gnutls

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mzlib)
CONFIGURE_ARGS+=	--with-zlib
.  include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl
.  include "../../security/openssl/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--with-gnutls
.  include "../../security/gnutls/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mtcpwrappers)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if !empty(PKG_OPTIONS:Mident)
CONFIGURE_ARGS+=	--with-ident
.  include "../../security/libident/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpam)
CONFIGURE_ARGS+=	--with-pam
.  include "../../security/openpam/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Miconv)
CONFIGURE_ARGS+=	--with-iconv
.  include "../../converters/libiconv/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mngircd-sniffer)
CONFIGURE_ARGS+=	--enable-sniffer
.endif

.if !empty(PKG_OPTIONS:Mngircd-irc+)
CONFIGURE_ARGS+=	--enable-ircplus
.endif

.if !empty(PKG_OPTIONS:Mngircd-strictrfc)
CONFIGURE_ARGS+=	--enable-strict-rfc
.endif
