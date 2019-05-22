# $NetBSD$

BUILDLINK_TREE+=	go-fasthttp

.if !defined(GO_FASTHTTP_BUILDLINK3_MK)
GO_FASTHTTP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fasthttp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fasthttp?=	build

BUILDLINK_API_DEPENDS.go-fasthttp+=	go-fasthttp>=1.3.0
BUILDLINK_PKGSRCDIR.go-fasthttp?=	../../wip/go-fasthttp
.endif	# GO_FASTHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fasthttp
