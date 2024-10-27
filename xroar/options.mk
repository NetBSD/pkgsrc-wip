# $NetBSD: options.mk,v 1.3 2024/01/02 00:21:01 ryoon Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xroar

PKG_SUPPORTED_OPTIONS+=	alsa oss pulseaudio

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	alsa
.else
PKG_SUGGESTED_OPTIONS+=	oss
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--with-alsa
.include "../../audio/alsa-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if !empty(PKG_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
LDFLAGS+=		${LIBOSSAUDIO}
CONFIGURE_ARGS+=	--with-oss

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Set OSS device node
SUBST_FILES.oss+=	src/oss/ao_oss.c
SUBST_SED.oss+=		-e 's,/dev/dsp,${DEVOSSAUDIO},g'
.else
CONFIGURE_ARGS+=	--without-oss
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pulse
.else
CONFIGURE_ARGS+=	--without-pulse
.endif
