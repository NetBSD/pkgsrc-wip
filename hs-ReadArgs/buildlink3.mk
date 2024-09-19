# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ReadArgs

.if !defined(HS_READARGS_BUILDLINK3_MK)
HS_READARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ReadArgs+=	hs-ReadArgs>=1.2.1
BUILDLINK_ABI_DEPENDS.hs-ReadArgs+=	hs-ReadArgs>=1.2.1
BUILDLINK_PKGSRCDIR.hs-ReadArgs?=	../../wip/hs-ReadArgs

.endif	# HS_READARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ReadArgs
