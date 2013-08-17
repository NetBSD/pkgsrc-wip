# $NetBSD: buildlink3.mk,v 1.1 2013/08/17 09:03:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ReadArgs

.if !defined(HS_READARGS_BUILDLINK3_MK)
HS_READARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ReadArgs+=	hs-ReadArgs>=1.2.1
BUILDLINK_PKGSRCDIR.hs-ReadArgs?=	../../wip/hs-ReadArgs

.endif	# HS_READARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ReadArgs
