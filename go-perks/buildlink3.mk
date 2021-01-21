# $NetBSD$

BUILDLINK_TREE+=	go-perks

.if !defined(GO_PERKS_BUILDLINK3_MK)
GO_PERKS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-perks=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-perks?=		build

BUILDLINK_API_DEPENDS.go-perks+=	go-perks>=1.0.1
BUILDLINK_PKGSRCDIR.go-perks?=		../../wip/go-perks
.endif	# GO_PERKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-perks
