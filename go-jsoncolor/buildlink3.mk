# $NetBSD$

BUILDLINK_TREE+=	go-jsoncolor

.if !defined(GO_JSONCOLOR_BUILDLINK3_MK)
GO_JSONCOLOR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-jsoncolor=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-jsoncolor?=	build

BUILDLINK_API_DEPENDS.go-jsoncolor+=	go-jsoncolor>=0.3.0
BUILDLINK_PKGSRCDIR.go-jsoncolor?=	../../wip/go-jsoncolor

.include "../../wip/go-color/buildlink3.mk"
.endif	# GO_JSONCOLOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-jsoncolor
