# $NetBSD$

BUILDLINK_TREE+=	ffms2

.if !defined(FFMS2_BUILDLINK3_MK)
FFMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffms2+=	ffms2>=5.0
BUILDLINK_PKGSRCDIR.ffms2?=	../../wip/ffms2

.include "../../multimedia/ffmpeg8/buildlink3.mk"
.endif	# FFMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffms2
