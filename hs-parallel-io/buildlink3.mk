# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parallel-io

.if !defined(HS_PARALLEL_IO_BUILDLINK3_MK)
HS_PARALLEL_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parallel-io+=	hs-parallel-io>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-parallel-io+=	hs-parallel-io>=0.3.3
BUILDLINK_PKGSRCDIR.hs-parallel-io?=	../../wip/hs-parallel-io

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_PARALLEL_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel-io
