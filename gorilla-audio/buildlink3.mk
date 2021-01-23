# $NetBSD$
BUILDLINK_TREE+=	gorilla-audio

.if !defined(GORILLA_AUDIO_BUILDLINK3_MK)
GORILLA_AUDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gorilla-audio+=	gorilla-audio>=0.0.20201007
BUILDLINK_PKGSRCDIR.gorilla-audio?=	../../wip/gorilla-audio

.include "../../audio/openal-soft/buildlink3.mk"
.endif	# GORILLA_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-gorilla-audio
