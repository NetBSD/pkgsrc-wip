# $NetBSD$

BUILDLINK_TREE+=	go-httppath

.if !defined(GO_HTTPPATH_BUILDLINK3_MK)
GO_HTTPPATH_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-httppath=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-httppath?=	build

BUILDLINK_API_DEPENDS.go-httppath+=	go-httppath>=20170721
BUILDLINK_PKGSRCDIR.go-httppath?=	../../wip/go-httppath
.endif	# GO_HTTPPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-httppath
