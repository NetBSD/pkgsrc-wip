# $NetBSD$

BUILDLINK_TREE+=	go-collectd

.if !defined(GO_COLLECTD_BUILDLINK3_MK)
GO_COLLECTD_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-collectd=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-collectd?=	build

BUILDLINK_API_DEPENDS.go-collectd+=	go-collectd>=20150830
BUILDLINK_PKGSRCDIR.go-collectd?=	../../wip/go-collectd
.endif	# GO_COLLECTD_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-collectd
