# $NetBSD: buildlink3.mk,v 1.5 2013/09/25 13:09:44 szptvlfn Exp $

BUILDLINK_TREE+=	hs-primitive

.if !defined(HS_PRIMITIVE_BUILDLINK3_MK)
HS_PRIMITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-primitive+=	hs-primitive>=0.5.1
BUILDLINK_PKGSRCDIR.hs-primitive?=	../../wip/hs-primitive
.endif	# HS_PRIMITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-primitive
