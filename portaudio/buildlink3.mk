# $NetBSD: buildlink3.mk,v 1.3 2013/05/08 23:57:17 othyro Exp $

BUILDLINK_TREE+=	portaudio

.if !defined(PORTAUDIO_BUILDLINK3_MK)
PORTAUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=18.1
BUILDLINK_ABI_DEPENDS.portaudio+=	portaudio>=19
BUILDLINK_PKGSRCDIR.portaudio?=	../../wip/portaudio

pkgbase := portaudio
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.portaudio:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.portaudio:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"
.endif # PORTAUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-portaudio
