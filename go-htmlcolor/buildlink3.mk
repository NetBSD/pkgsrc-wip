# $NetBSD$

BUILDLINK_TREE+=	go-htmlcolor

.if !defined(GO_HTMLCOLOR_BUILDLINK3_MK)
GO_HTMLCOLOR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-htmlcolor=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-htmlcolor?=	build

BUILDLINK_API_DEPENDS.go-htmlcolor+=	go-htmlcolor>=20190529
BUILDLINK_PKGSRCDIR.go-htmlcolor?=	../../wip/go-htmlcolor

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-color/buildlink3.mk"
.endif	# GO_HTMLCOLOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-htmlcolor
