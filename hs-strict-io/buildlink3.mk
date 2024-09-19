# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-strict-io

.if !defined(HS_STRICT_IO_BUILDLINK3_MK)
HS_STRICT_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict-io+=	hs-strict-io>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-strict-io+=	hs-strict-io>=0.2.1
BUILDLINK_PKGSRCDIR.hs-strict-io?=	../../wip/hs-strict-io

.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.endif	# HS_STRICT_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict-io
