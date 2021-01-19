# $NetBSD$

BUILDLINK_TREE+=	go-gabs

.if !defined(GO_GABS_BUILDLINK3_MK)
GO_GABS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gabs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gabs?=		build

BUILDLINK_API_DEPENDS.go-gabs+=	go-gabs>=2.6.0
BUILDLINK_PKGSRCDIR.go-gabs?=	../../wip/go-gabs
.endif	# GO_GABS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gabs
