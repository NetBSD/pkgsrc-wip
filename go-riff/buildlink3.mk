# $NetBSD$

BUILDLINK_TREE+=	go-riff

.if !defined(GO_RIFF_BUILDLINK3_MK)
GO_RIFF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-riff=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-riff?=		build

BUILDLINK_API_DEPENDS.go-riff+=	go-riff>=1.0.0
BUILDLINK_PKGSRCDIR.go-riff?=	../../wip/go-riff
.endif	# GO_RIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-riff
