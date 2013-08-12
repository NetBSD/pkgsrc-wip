# $NetBSD: options.mk,v 1.2 2013/08/12 02:51:45 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.yateclient
PKG_SUPPORTED_OPTIONS=	alsa doc gsm ilbc spandsp speex
PKG_SUGGESTED_OPTIONS+=	gsm ilbc spandsp speex # blank
PLIST_VARS+=		doc gsm spandsp speex

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mdoc)
# XXX also use kdoc for doc option
BUILD_DEPENDS+=		doxygen-[0-9]*:../../devel/doxygen
CONFIGURE_ARGS+=	--with-doxygen=yes
PLIST.doc=		yes
.else
CONFIGURE_ARGS+=	--with-doxygen=no
.endif

.if !empty(PKG_OPTIONS:Mgsm)
.include "../../audio/gsm/buildlink3.mk"
PLIST.gsm=		yes
.endif

.if !empty(PKG_OPTIONS:Milbc)
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mspandsp)
.include "../../comms/spandsp/buildlink3.mk"
PLIST.spandsp=		yes
.endif

.if !empty(PKG_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
PLIST.speex=		yes
.endif
