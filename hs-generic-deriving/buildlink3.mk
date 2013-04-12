# $NetBSD: buildlink3.mk,v 1.1 2013/04/12 20:24:15 szptvlfn Exp $

BUILDLINK_TREE+=	hs-generic-deriving

.if !defined(HS_GENERIC_DERIVING_BUILDLINK3_MK)
HS_GENERIC_DERIVING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-deriving+=	hs-generic-deriving>=1.5.0
BUILDLINK_PKGSRCDIR.hs-generic-deriving?=	../../wip/hs-generic-deriving
.endif	# HS_GENERIC_DERIVING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-deriving
