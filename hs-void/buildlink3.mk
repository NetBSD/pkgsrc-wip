# $NetBSD: buildlink3.mk,v 1.1 2013/03/09 12:52:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.5.12
BUILDLINK_PKGSRCDIR.hs-void?=	../../wip/hs-void

.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
