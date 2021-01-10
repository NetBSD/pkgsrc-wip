# $NetBSD$

BUILDLINK_TREE+=	go-freetype

.if !defined(GO_FREETYPE_BUILDLINK3_MK)
GO_FREETYPE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-freetype=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-freetype?=		build

BUILDLINK_API_DEPENDS.go-freetype+=	go-freetype>=20170609
BUILDLINK_PKGSRCDIR.go-freetype?=	../../category/go-freetype


.include "../../graphics/go-image/buildlink3.mk"
.endif	# GO_FREETYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-freetype
