# $NetBSD$

BUILDLINK_TREE+=	rubberband

.if !defined(RUBBERBAND_BUILDLINK3_MK)
RUBBERBAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rubberband+=	rubberband>=1.8.1
BUILDLINK_PKGSRCDIR.rubberband?=	../../wip/rubberband

.include "../../audio/ladspa/buildlink3.mk"
.include "../../wip/vamp-plugin-sdk/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.endif	# RUBBERBAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-rubberband
