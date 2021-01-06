# $NetBSD$

BUILDLINK_TREE+=	go-intern

.if !defined(GO_INTERN_BUILDLINK3_MK)
GO_INTERN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-intern=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-intern?=		build

BUILDLINK_API_DEPENDS.go-intern+=	go-intern>=1.0.0
BUILDLINK_PKGSRCDIR.go-intern?=	../../wip/go-intern
.endif	# GO_INTERN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-intern
