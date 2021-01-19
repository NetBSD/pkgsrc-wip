# $NetBSD$

BUILDLINK_TREE+=	go-fasttemplate

.if !defined(GO_FASTTEMPLATE_BUILDLINK3_MK)
GO_FASTTEMPLATE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fasttemplate=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fasttemplate?=		build

BUILDLINK_API_DEPENDS.go-fasttemplate+=	go-fasttemplate>=1.2.1
BUILDLINK_PKGSRCDIR.go-fasttemplate?=	../../wip/go-fasttemplate
.endif	# GO_FASTTEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fasttemplate
