# $NetBSD: options.mk,v 1.1 2007/05/24 01:43:37 bsadewitz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.aria2
PKG_OPTIONS_GROUP.https= gnutls openssl
PKG_OPTIONS_GROUP.asyncns= libares libcares
PKG_OPTIONS_REQUIRED_GROUPS= https
PKG_OPTIONS_OPTIONAL_GROUPS= asyncns
PKG_SUPPORTED_OPTIONS+=libxml2

CHECK_BUILTIN.openssl:=yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=no

.if !empty(IS_BUILTIN.openssl:M[Yy][Ee][Ss])
PKG_SUGGESTED_OPTIONS+=	openssl
.else
PKG_SUGGESTED_OPTIONS+= gnutls
.endif

PKG_SUGGESTED_OPTIONS+=	libxml2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mopenssl)
CONFIGURE_ARGS+=	--with-openssl
CONFIGURE_ARGS+=	--without-gnutls
.  include "../../security/openssl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-gnutls
CONFIGURE_ARGS+=	--without-openssl
.  include "../../security/gnutls/buildlink3.mk"
.endif
CONFIGURE_ARGS+=	--enable-bittorrent	# Either one or the other above
						# is required, so this works.

.if !empty(PKG_OPTIONS:Mlibcares)
CONFIGURE_ARGS+=	--with-libcares-prefix=${BUILDLINK_PREFIX.libcares:Q}
.  include "../../net/libcares/buildlink3.mk"
.elif !empty(PKG_OPTIONS:Mlibares)
CONFIGURE_ARGS+=	--with-libares-prefix=${BUILDLINK_PREFIX.libares:Q}
.endif


.if !empty(PKG_OPTIONS:Mlibxml2)
CONFIGURE_ARGS+=	--with-libxml2
CONFIGURE_ARGS+=	--enable-metalink
CONFIGURE_ARGS+=	--with-xml-prefix=${BULDLINK_PREFIX.libxml2:Q}
.  include "../../textproc/libxml2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libxml2
CONFIGURE_ARGS+=	--disable-metalink
.endif
