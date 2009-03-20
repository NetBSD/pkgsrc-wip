# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-parallel

.if !defined(HS_PARALLEL_BUILDLINK3_MK)
HS_PARALLEL_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-parallel?=	build
BUILDLINK_API_DEPENDS.hs-parallel+=	hs-parallel>=1.1.0.0
BUILDLINK_PKGSRCDIR.hs-parallel?=	../../wip/hs-parallel
.endif # HS_PARALLEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel
