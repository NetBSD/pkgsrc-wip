# $NetBSD$

BUILDLINK_TREE+=	go-jennifer

.if !defined(GO_JENNIFER_BUILDLINK3_MK)
GO_JENNIFER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jennifer=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jennifer?=	build

BUILDLINK_API_DEPENDS.go-jennifer+=	go-jennifer>=1.4.1
BUILDLINK_PKGSRCDIR.go-jennifer?=	../../wip/go-jennifer
.endif	# GO_JENNIFER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jennifer
