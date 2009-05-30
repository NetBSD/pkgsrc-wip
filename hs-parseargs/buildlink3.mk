# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/30 09:46:56 phonohawk Exp $

BUILDLINK_TREE+=	hs-parseargs

.if !defined(HS_PARSEARGS_BUILDLINK3_MK)
HS_PARSEARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parseargs+=	hs-parseargs>=0.1.2
BUILDLINK_PKGSRCDIR.hs-parseargs?=	../../wip/hs-parseargs
.endif	# HS_PARSEARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parseargs
