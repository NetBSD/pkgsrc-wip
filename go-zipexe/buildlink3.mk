# $NetBSD$

BUILDLINK_TREE+=	go-zipexe

.if !defined(GO_ZIPEXE_BUILDLINK3_MK)
GO_ZIPEXE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-zipexe=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-zipexe?=		build

BUILDLINK_API_DEPENDS.go-zipexe+=	go-zipexe>=1.0.1
BUILDLINK_PKGSRCDIR.go-zipexe?=		../../wip/go-zipexe
.endif	# GO_ZIPEXE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-zipexe
