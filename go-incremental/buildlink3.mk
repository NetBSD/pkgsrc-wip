# $NetBSD$

BUILDLINK_TREE+=	go-incremental

.if !defined(GO_INCREMENTAL_BUILDLINK3_MK)
GO_INCREMENTAL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-incremental=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-incremental?=		build

BUILDLINK_API_DEPENDS.go-incremental+=	go-incremental>=1.0.0
BUILDLINK_PKGSRCDIR.go-incremental?=	../../wip/go-incremental
.endif	# GO_INCREMENTAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-incremental
