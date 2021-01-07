# $NetBSD$

BUILDLINK_TREE+=	go-tiff

.if !defined(GO_TIFF_BUILDLINK3_MK)
GO_TIFF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tiff=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tiff?=		build

BUILDLINK_API_DEPENDS.go-tiff+=	go-tiff>=20190829nb1
BUILDLINK_PKGSRCDIR.go-tiff?=	../../wip/go-tiff


.include "../../graphics/go-image/buildlink3.mk"
.include "../../wip/go-lzw/buildlink3.mk"
.endif	# GO_TIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tiff
