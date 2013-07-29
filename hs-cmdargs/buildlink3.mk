# $NetBSD: buildlink3.mk,v 1.1 2013/07/29 20:09:58 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.5
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../wip/hs-cmdargs

.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
