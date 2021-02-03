# $NetBSD$

BUILDLINK_TREE+=	go-netlink

.if !defined(GO_NETLINK_BUILDLINK3_MK)
GO_NETLINK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-netlink=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-netlink?=	build

BUILDLINK_API_DEPENDS.go-netlink+=	go-netlink>=20210111
BUILDLINK_PKGSRCDIR.go-netlink?=	../../category/go-netlink

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-native/buildlink3.mk"
.endif	# GO_NETLINK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-netlink
