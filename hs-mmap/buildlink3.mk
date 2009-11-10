# $NetBSD: buildlink3.mk,v 1.2 2009/11/10 07:34:50 phonohawk Exp $

BUILDLINK_TREE+=	hs-mmap

.if !defined(HS_MMAP_BUILDLINK3_MK)
HS_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap+=	hs-mmap>=0.5.4
BUILDLINK_PKGSRCDIR.hs-mmap?=	../../wip/hs-mmap
.endif	# HS_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap
