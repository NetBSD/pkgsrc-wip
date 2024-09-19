# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parseargs

.if !defined(HS_PARSEARGS_BUILDLINK3_MK)
HS_PARSEARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parseargs+=	hs-parseargs>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-parseargs+=	hs-parseargs>=0.1.5.2
BUILDLINK_PKGSRCDIR.hs-parseargs?=	../../wip/hs-parseargs
.endif	# HS_PARSEARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parseargs
