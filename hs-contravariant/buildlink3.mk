# $NetBSD: buildlink3.mk,v 1.2 2013/04/20 04:35:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-contravariant

.if !defined(HS_CONTRAVARIANT_BUILDLINK3_MK)
HS_CONTRAVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-contravariant+=	hs-contravariant>=0.4
BUILDLINK_PKGSRCDIR.hs-contravariant?=	../../wip/hs-contravariant

.endif	# HS_CONTRAVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-contravariant
