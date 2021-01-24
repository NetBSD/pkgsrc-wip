# $NetBSD$

BUILDLINK_TREE+=	go-rtcp

.if !defined(GO_RTCP_BUILDLINK3_MK)
GO_RTCP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-rtcp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-rtcp?=		build

BUILDLINK_API_DEPENDS.go-rtcp+=	go-rtcp>=1.2.6
BUILDLINK_PKGSRCDIR.go-rtcp?=	../../wip/go-rtcp
.endif	# GO_RTCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-rtcp
