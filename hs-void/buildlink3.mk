# $NetBSD: buildlink3.mk,v 1.2 2013/04/21 22:21:31 szptvlfn Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.6
BUILDLINK_PKGSRCDIR.hs-void?=	../../wip/hs-void

.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
