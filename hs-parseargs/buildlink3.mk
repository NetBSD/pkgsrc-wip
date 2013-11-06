# $NetBSD: buildlink3.mk,v 1.2 2013/11/06 12:06:44 szptvlfn Exp $

BUILDLINK_TREE+=	hs-parseargs

.if !defined(HS_PARSEARGS_BUILDLINK3_MK)
HS_PARSEARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-parseargs+=	hs-parseargs>=0.1.5
BUILDLINK_PKGSRCDIR.hs-parseargs?=	../../wip/hs-parseargs
.endif	# HS_PARSEARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-parseargs
