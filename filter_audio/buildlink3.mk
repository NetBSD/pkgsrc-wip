# $NetBSD$

BUILDLINK_TREE+=	filter_audio

.if !defined(FILTER_AUDIO_BUILDLINK3_MK)
FILTER_AUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.filter_audio+=	filter_audio>=0.0.0.0
BUILDLINK_PKGSRCDIR.filter_audio?=	../../wip/filter_audio
.endif	# FILTER_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-filter_audio
