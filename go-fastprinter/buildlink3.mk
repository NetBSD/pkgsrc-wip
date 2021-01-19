# $NetBSD$

BUILDLINK_TREE+=	go-fastprinter

.if !defined(GO_FASTPRINTER_BUILDLINK3_MK)
GO_FASTPRINTER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fastprinter=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fastprinter?=		build

BUILDLINK_API_DEPENDS.go-fastprinter+=	go-fastprinter>=20200109
BUILDLINK_PKGSRCDIR.go-fastprinter?=	../../wip/go-fastprinter
.endif	# GO_FASTPRINTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fastprinter
