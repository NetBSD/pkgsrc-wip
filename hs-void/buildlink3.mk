# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-void

.if !defined(HS_VOID_BUILDLINK3_MK)
HS_VOID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-void+=	hs-void>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-void+=	hs-void>=0.6.1
BUILDLINK_PKGSRCDIR.hs-void?=	../../wip/hs-void

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../wip/hs-semigroups/buildlink3.mk"
.endif	# HS_VOID_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-void
