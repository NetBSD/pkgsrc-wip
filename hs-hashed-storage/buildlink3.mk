# $NetBSD: buildlink3.mk,v 1.13 2014/08/29 14:10:14 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hashed-storage

.if !defined(HS_HASHED_STORAGE_BUILDLINK3_MK)
HS_HASHED_STORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashed-storage+=	hs-hashed-storage>=0.5.10
BUILDLINK_ABI_DEPENDS.hs-hashed-storage+=	hs-hashed-storage>=0.5.10
BUILDLINK_PKGSRCDIR.hs-hashed-storage?=		../../wip/hs-hashed-storage

.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../devel/hs-extensible-exceptions/buildlink3.mk"
.include "../../wip/hs-mmap/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_HASHED_STORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashed-storage
