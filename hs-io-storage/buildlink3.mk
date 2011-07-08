# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 09:58:31 phonohawk Exp $

BUILDLINK_TREE+=	hs-io-storage

.if !defined(HS_IO_STORAGE_BUILDLINK3_MK)
HS_IO_STORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-io-storage+=	hs-io-storage>=0.3
BUILDLINK_PKGSRCDIR.hs-io-storage?=	../../wip/hs-io-storage
.endif	# HS_IO_STORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-io-storage
