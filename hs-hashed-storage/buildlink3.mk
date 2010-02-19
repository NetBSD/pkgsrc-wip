# $NetBSD: buildlink3.mk,v 1.6 2010/02/19 03:24:41 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashed-storage

.if !defined(HS_HASHED_STORAGE_BUILDLINK3_MK)
HS_HASHED_STORAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashed-storage+=	hs-hashed-storage>=0.4.7
BUILDLINK_PKGSRCDIR.hs-hashed-storage?=	../../wip/hs-hashed-storage

.include "../../wip/hs-binary/buildlink3.mk"
.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../wip/hs-mmap4/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.endif	# HS_HASHED_STORAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashed-storage
