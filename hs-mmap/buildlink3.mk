# $NetBSD: buildlink3.mk,v 1.3 2011/01/07 09:31:57 phonohawk Exp $

BUILDLINK_TREE+=	hs-mmap

.if !defined(HS_MMAP_BUILDLINK3_MK)
HS_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap+=	hs-mmap>=0.5
BUILDLINK_PKGSRCDIR.hs-mmap?=	../../wip/hs-mmap
.endif	# HS_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap
