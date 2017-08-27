# $NetBSD$

BUILDLINK_TREE+=	go-humanize

.if !defined(GO_HUMANIZE_BUILDLINK3_MK)
GO_HUMANIZE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-humanize=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-humanize?=		build

BUILDLINK_API_DEPENDS.go-humanize+=	go-humanize>=0.0.1
BUILDLINK_PKGSRCDIR.go-humanize?=	../../wip/go-humanize
.endif	# GO_HUMANIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-humanize
