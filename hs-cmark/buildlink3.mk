# $NetBSD$

BUILDLINK_TREE+=	hs-cmark

.if !defined(HS_CMARK_BUILDLINK3_MK)
HS_CMARK_BUILDLINK3_MK:=	# defined

BUILDLINK_API_DEPENDS.hs-cmark+=	hs-cmark>=0.6
BUILDLINK_ABI_DEPENDS.hs-cmark+=	hs-cmark>=0.6
BUILDLINK_PKGSRCDIR.hs-cmark?=		../../wip/hs-cmark

.endif	# HS_CMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmark
