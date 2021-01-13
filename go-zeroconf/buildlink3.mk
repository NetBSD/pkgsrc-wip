# $NetBSD$

BUILDLINK_TREE+=	go-zeroconf

.if !defined(GO_ZEROCONF_BUILDLINK3_MK)
GO_ZEROCONF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-zeroconf=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-zeroconf?=	build

BUILDLINK_API_DEPENDS.go-zeroconf+=	go-zeroconf>=1.0.0
BUILDLINK_PKGSRCDIR.go-zeroconf?=	../../category/go-zeroconf

.include "../../net/go-dns/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-backoff/buildlink3.mk"
.endif	# GO_ZEROCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-zeroconf
