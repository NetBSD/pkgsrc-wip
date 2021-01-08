# $NetBSD$

BUILDLINK_TREE+=	go-clir

.if !defined(GO_CLIR_BUILDLINK3_MK)
GO_CLIR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-clir=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-clir?=		build

BUILDLINK_API_DEPENDS.go-clir+=	go-clir>=1.0.2
BUILDLINK_PKGSRCDIR.go-clir?=	../../wip/go-clir
.endif	# GO_CLIR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-clir
