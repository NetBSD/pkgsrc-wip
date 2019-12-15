PKG_OPTIONS_VAR=	PKG_OPTIONS.ngircd
PKG_SUPPORTED_OPTIONS=	zlib openssl gnutls tcpwrap ident pam iconv ipv6 sniffer irc+ strictrfc
PKG_SUGGESTED_OPTIONS=	zlib ident ipv6

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

.if !empty(PKG_OPTIONS:Mtcpwrap)
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

.if !empty(PKG_OPTIONS:Mipv6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !empty(PKG_OPTIONS:Msniffer)
CONFIGURE_ARGS+=	--enable-sniffer
.endif

.if !empty(PKG_OPTIONS:Mirc+)
CONFIGURE_ARGS+=	--enable-ircplus
.endif

.if !empty(PKG_OPTIONS:Mstrictrfc)
CONFIGURE_ARGS+=	--enable-strict-rfc
.endif
