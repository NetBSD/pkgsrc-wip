# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:14:27 cheusov Exp $

BUILDLINK_TREE+=	pxlib

.if !defined(PXLIB_BUILDLINK3_MK)
PXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pxlib+=	pxlib>=0.2.0
BUILDLINK_PKGSRCDIR.pxlib?=	../../wip/pxlib

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.endif # PXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pxlib
