# $NetBSD$

BUILDLINK_TREE+=	libopenshot-audio

.if !defined(LIBOPENSHOT_AUDIO_BUILDLINK3_MK)
LIBOPENSHOT_AUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenshot-audio+=	libopenshot-audio>=0.4.0
BUILDLINK_PKGSRCDIR.libopenshot-audio?=		../../wip/libopenshot-audio

.endif	# LIBOPENSHOT_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenshot-audio
