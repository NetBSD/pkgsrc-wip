# $NetBSD: buildlink3.mk,v 1.2 2013/08/31 04:51:52 szptvlfn Exp $

BUILDLINK_TREE+=	hs-generic-deriving

.if !defined(HS_GENERIC_DERIVING_BUILDLINK3_MK)
HS_GENERIC_DERIVING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-deriving+=	hs-generic-deriving>=1.6.1
BUILDLINK_PKGSRCDIR.hs-generic-deriving?=	../../wip/hs-generic-deriving
.endif	# HS_GENERIC_DERIVING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-deriving
