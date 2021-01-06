# $NetBSD$

BUILDLINK_TREE+=	go-audio

.if !defined(GO_AUDIO_BUILDLINK3_MK)
GO_AUDIO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-audio=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-audio?=		build

BUILDLINK_API_DEPENDS.go-audio+=	go-audio>=1.0.0
BUILDLINK_PKGSRCDIR.go-audio?=	../../wip/go-audio
.endif	# GO_AUDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-audio
