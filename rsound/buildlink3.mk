# $NetBSD: buildlink3.mk,v 1.4 2012/12/17 12:52:12 thomasklausner Exp $

BUILDLINK_TREE+=	rsound

.if !defined(RSOUND_BUILDLINK3_MK)
RSOUND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rsound+=	rsound>=1.1
BUILDLINK_PKGSRCDIR.rsound?=	../../wip/rsound

pkgbase := rsound
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.rsound:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Mlibao)
.include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Mopenal)
.include "../../audio/openal-soft/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Mportaudio)
.include "../../audio/portaudio/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.rsound:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
.endif	# RSOUND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rsound
