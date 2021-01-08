# $NetBSD$

BUILDLINK_TREE+=	go-errorx

.if !defined(GO_ERRORX_BUILDLINK3_MK)
GO_ERRORX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-errorx=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-errorx?=		build

BUILDLINK_API_DEPENDS.go-errorx+=	go-errorx>=1.0.3
BUILDLINK_PKGSRCDIR.go-errorx?=		../../wip/go-errorx
.endif	# GO_ERRORX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-errorx
