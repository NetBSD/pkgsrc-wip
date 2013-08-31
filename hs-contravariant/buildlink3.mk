# $NetBSD: buildlink3.mk,v 1.3 2013/08/31 05:26:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=0.4.4
BUILDLINK_PKGSRCDIR.hs-contravariant?=	../../wip/hs-contravariant

.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
