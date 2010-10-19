# $NetBSD: buildlink3.mk,v 1.1 2010/10/19 21:52:31 othyro Exp $

BUILDLINK_TREE+=	tkpng

.if !defined(TKPNG_BUILDLINK3_MK)
TKPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tkpng+=	tkpng>=0.9
BUILDLINK_PKGSRCDIR.tkpng?=	../../wip/tkpng
.endif # TKPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-tkpng
