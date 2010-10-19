# $NetBSD: buildlink3.mk,v 1.2 2010/10/19 21:55:16 othyro Exp $

BUILDLINK_TREE+=	tkpng

.if !defined(TKPNG_BUILDLINK3_MK)
TKPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tkpng+=	tkpng>=0.9
BUILDLINK_PKGSRCDIR.tkpng?=	../../wip/tkpng

.include "../../wip/tk85/buildlink3.mk"
.endif # TKPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-tkpng
