# $NetBSD$

BUILDLINK_TREE+=	go-aurora

.if !defined(GO_AURORA_BUILDLINK3_MK)
GO_AURORA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-aurora=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-aurora?=		build

BUILDLINK_API_DEPENDS.go-aurora+=	go-aurora>=3.0.0
BUILDLINK_PKGSRCDIR.go-aurora?=	../../wip/go-aurora
.endif	# GO_AURORA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-aurora
