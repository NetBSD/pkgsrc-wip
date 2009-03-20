# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	pxlib

BUILDLINK_API_DEPENDS.pxlib+=	pxlib>=0.2.0
BUILDLINK_PKGSRCDIR.pxlib?=	../../wip/pxlib

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.endif # PXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pxlib
