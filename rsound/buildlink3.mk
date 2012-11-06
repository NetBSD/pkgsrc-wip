# $NetBSD: buildlink3.mk,v 1.2 2012/11/06 14:50:30 othyro Exp $

BUILDLINK_TREE+=	rsound

.if !defined(RSOUND_BUILDLINK3_MK)
RSOUND_BUILDLINK3_MK:=

pkgbase := rsound
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mlibao)
.include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mopenal)
.include "../../audio/openal/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.rsound+=	rsound>=1.1
BUILDLINK_PKGSRCDIR.rsound?=	../../wip/rsound
.endif	# RSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rsound
