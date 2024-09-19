# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-lazy-io

.if !defined(HS_LAZY_IO_BUILDLINK3_MK)
HS_LAZY_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-lazy-io+=	hs-lazy-io>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-lazy-io+=	hs-lazy-io>=0.1.0
BUILDLINK_PKGSRCDIR.hs-lazy-io?=	../../wip/hs-lazy-io
.endif	# HS_LAZY_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-lazy-io
