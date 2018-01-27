# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmap4

.if !defined(HS_MMAP4_BUILDLINK3_MK)
HS_MMAP4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap4+=	hs-mmap4>=0.4.1
BUILDLINK_ABI_DEPENDS.hs-mmap4+=	hs-mmap4>=0.4.1
BUILDLINK_PKGSRCDIR.hs-mmap4?=		../../wip/hs-mmap4
.endif	# HS_MMAP4_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap4
