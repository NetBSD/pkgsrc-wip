# $NetBSD$

BUILDLINK_TREE+=	go-httphead

.if !defined(GO_HTTPHEAD_BUILDLINK3_MK)
GO_HTTPHEAD_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-httphead=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-httphead?=	build

BUILDLINK_API_DEPENDS.go-httphead+=	go-httphead>=0.1.0
BUILDLINK_PKGSRCDIR.go-httphead?=	../../wip/go-httphead
.endif	# GO_HTTPHEAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-httphead
