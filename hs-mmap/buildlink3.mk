# $NetBSD: buildlink3.mk,v 1.4 2012/03/04 07:27:17 phonohawk Exp $

BUILDLINK_TREE+=	hs-mmap

.if !defined(HS_MMAP_BUILDLINK3_MK)
HS_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap+=	hs-mmap>=0.5.7
BUILDLINK_PKGSRCDIR.hs-mmap?=	../../wip/hs-mmap
.endif	# HS_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap
