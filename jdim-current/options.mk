# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.jdim
PKG_SUPPORTED_OPTIONS=		alsa migemo
PKG_OPTIONS_REQUIRED_GROUPS=	tls
PKG_OPTIONS_GROUP.tls=		gnutls openssl
PKG_SUGGESTED_OPTIONS=		gnutls migemo

.include "../../mk/bsd.options.mk"

###
### Play sound effects using ALSA
###
.if !empty(PKG_OPTIONS:Malsa)
MESON_ARGS+=	-Dalsa=enabled
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif

###
### Search Japanese text using Migemo
###
.if !empty(PKG_OPTIONS:Mmigemo)
MESON_ARGS+=	-Dmigemo=enabled -Dmigemodict=${PREFIX:Q}/share/migemo/utf-8/migemo-dict
.  include "../../textproc/cmigemo/buildlink3.mk"
.endif

###
### Use GnuTLS for TLS
###
.if !empty(PKG_OPTIONS:Mgnutls)
MESON_ARGS+=	-Dtls=gnutls
.  include "../../security/gnutls/buildlink3.mk"
.endif

###
### Use OpenSSL for TLS
###
.if !empty(PKG_OPTIONS:Mopenssl)
MESON_ARGS+=	-Dtls=openssl
.  include "../../security/openssl/buildlink3.mk"
.endif
