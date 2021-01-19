# $NetBSD$

BUILDLINK_TREE+=	go-ffmpeg

.if !defined(GO_FFMPEG_BUILDLINK3_MK)
GO_FFMPEG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ffmpeg=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ffmpeg?=		build

BUILDLINK_API_DEPENDS.go-ffmpeg+=	go-ffmpeg>=0.5.0
BUILDLINK_PKGSRCDIR.go-ffmpeg?=	../../wip/go-ffmpeg
.endif	# GO_FFMPEG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ffmpeg
