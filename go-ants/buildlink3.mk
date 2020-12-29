# $NetBSD$

BUILDLINK_TREE+=	go-ants

.if !defined(GO_ANTS_BUILDLINK3_MK)
GO_ANTS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ants=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ants?=		build

BUILDLINK_API_DEPENDS.go-ants+=	go-ants>=2.4.0
BUILDLINK_PKGSRCDIR.go-ants?=	../../wip/go-ants
.endif	# GO_ANTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ants
