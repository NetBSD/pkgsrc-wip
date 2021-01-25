# $NetBSD$

BUILDLINK_TREE+=	go-influxdb1-client

.if !defined(GO_INFLUXDB1_CLIENT_BUILDLINK3_MK)
GO_INFLUXDB1_CLIENT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-influxdb1-client=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-influxdb1-client?=	build

BUILDLINK_API_DEPENDS.go-influxdb1-client+=	go-influxdb1-client>=20200827
BUILDLINK_PKGSRCDIR.go-influxdb1-client?=	../../wip/go-influxdb1-client
.endif	# GO_INFLUXDB1_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-influxdb1-client
