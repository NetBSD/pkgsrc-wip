# $NetBSD$

BUILDLINK_TREE+=	go-rsrc

.if !defined(GO_RSRC_BUILDLINK3_MK)
GO_RSRC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-rsrc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-rsrc?=		build

BUILDLINK_API_DEPENDS.go-rsrc+=	go-rsrc>=0.10.1
BUILDLINK_PKGSRCDIR.go-rsrc?=	../../wip/go-rsrc
.endif	# GO_RSRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-rsrc
