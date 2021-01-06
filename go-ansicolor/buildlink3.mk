# $NetBSD$

BUILDLINK_TREE+=	go-ansicolor

.if !defined(GO_ANSICOLOR_BUILDLINK3_MK)
GO_ANSICOLOR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ansicolor=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ansicolor?=		build

BUILDLINK_API_DEPENDS.go-ansicolor+=	go-ansicolor>=20200904
BUILDLINK_PKGSRCDIR.go-ansicolor?=	../../wip/go-ansicolor
.endif	# GO_ANSICOLOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ansicolor
