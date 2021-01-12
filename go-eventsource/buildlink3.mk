# $NetBSD$

BUILDLINK_TREE+=	go-eventsource

.if !defined(GO_EVENTSOURCE_BUILDLINK3_MK)
GO_EVENTSOURCE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-eventsource=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-eventsource?=		build

BUILDLINK_API_DEPENDS.go-eventsource+=	go-eventsource>=20170931
BUILDLINK_PKGSRCDIR.go-eventsource?=	../../wip/go-eventsource
.endif	# GO_EVENTSOURCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-eventsource
