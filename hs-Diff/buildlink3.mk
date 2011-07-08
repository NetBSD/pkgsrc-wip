# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 09:13:08 phonohawk Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.1
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../wip/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
