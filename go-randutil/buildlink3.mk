# $NetBSD$

BUILDLINK_TREE+=	go-randutil

.if !defined(GO_RANDUTIL_BUILDLINK3_MK)
GO_RANDUTIL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-randutil=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-randutil?=	build

BUILDLINK_API_DEPENDS.go-randutil+=	go-randutil>=0.1.0
BUILDLINK_PKGSRCDIR.go-randutil?=	../../wip/go-randutil
.endif	# GO_RANDUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-randutil
