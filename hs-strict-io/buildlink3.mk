# $NetBSD: buildlink3.mk,v 1.1 2013/05/01 19:48:23 szptvlfn Exp $

BUILDLINK_TREE+=	hs-strict-io

.if !defined(HS_STRICT_IO_BUILDLINK3_MK)
HS_STRICT_IO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-strict-io+=	hs-strict-io>=0.2.1
BUILDLINK_PKGSRCDIR.hs-strict-io?=	../../wip/hs-strict-io
.endif	# HS_STRICT_IO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-strict-io
