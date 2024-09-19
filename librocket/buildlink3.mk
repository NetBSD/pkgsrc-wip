# $NetBSD$

BUILDLINK_TREE+=	librocket

.if !defined(LIBROCKET_BUILDLINK3_MK)
LIBROCKET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librocket+=	librocket>=1.3.0.0
BUILDLINK_ABI_DEPENDS.librocket+=	librocket>=1.3.0.0
BUILDLINK_PKGSRCDIR.librocket?=		../../wip/librocket

.include "../../graphics/freetype2/buildlink3.mk"
.endif # LIBROCKET_BUILDLINK3_MK

BUILDLINK_TREE+=	-librocket
