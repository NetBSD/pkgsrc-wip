# $NetBSD$

BUILDLINK_TREE+=	go-kong

.if !defined(GO_KONG_BUILDLINK3_MK)
GO_KONG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-kong=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-kong?=		build

BUILDLINK_API_DEPENDS.go-kong+=		go-kong>=0.2.6
BUILDLINK_PKGSRCDIR.go-kong?=		../../wip/go-kong

.include "../../devel/go-errors/buildlink3.mk"
.endif	# GO_KONG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-kong
