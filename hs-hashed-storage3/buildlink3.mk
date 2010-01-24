# $NetBSD: buildlink3.mk,v 1.2 2010/01/24 03:13:45 phonohawk Exp $

BUILDLINK_TREE+=	hs-hashed-storage3

.if !defined(HS_HASHED_STORAGE3_BUILDLINK3_MK)
HS_HASHED_STORAGE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashed-storage3+=	hs-hashed-storage3>=0.3.9
BUILDLINK_PKGSRCDIR.hs-hashed-storage3?=	../../wip/hs-hashed-storage3

.include "../../wip/hs-mmap4/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.endif	# HS_HASHED_STORAGE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashed-storage3
