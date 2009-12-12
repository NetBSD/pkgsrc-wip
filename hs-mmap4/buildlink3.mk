# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/12/12 15:06:31 phonohawk Exp $

BUILDLINK_TREE+=	hs-mmap4

.if !defined(HS_MMAP4_BUILDLINK3_MK)
HS_MMAP4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmap4+=	hs-mmap4>=0.4.1
BUILDLINK_PKGSRCDIR.hs-mmap4?=	../../wip/hs-mmap4
.endif	# HS_MMAP4_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmap4
