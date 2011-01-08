# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/08 04:42:00 phonohawk Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.3
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../wip/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
