# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-newtype

.if !defined(HS_NEWTYPE_BUILDLINK3_MK)
HS_NEWTYPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-newtype+=	hs-newtype>=0.2
BUILDLINK_ABI_DEPENDS.hs-newtype+=	hs-newtype>=0.2
BUILDLINK_PKGSRCDIR.hs-newtype?=	../../wip/hs-newtype
.endif	# HS_NEWTYPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-newtype
