# $NetBSD: buildlink3.mk,v 1.2 2012/03/11 05:59:00 phonohawk Exp $

BUILDLINK_TREE+=	hs-Diff

.if !defined(HS_DIFF_BUILDLINK3_MK)
HS_DIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Diff+=	hs-Diff>=0.1.3
BUILDLINK_PKGSRCDIR.hs-Diff?=	../../wip/hs-Diff
.endif	# HS_DIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Diff
