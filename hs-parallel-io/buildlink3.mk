# $NetBSD: buildlink3.mk,v 1.3 2014/05/20 21:23:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parallel-io

.if !defined(HS_PARALLEL_IO_BUILDLINK3_MK)
HS_PARALLEL_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parallel-io+=	hs-parallel-io>=0.3.3
BUILDLINK_PKGSRCDIR.hs-parallel-io?=	../../wip/hs-parallel-io

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.endif	# HS_PARALLEL_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parallel-io
