# $NetBSD: buildlink3.mk,v 1.2 2013/12/05 23:05:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cmdargs

.if !defined(HS_CMDARGS_BUILDLINK3_MK)
HS_CMDARGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cmdargs+=	hs-cmdargs>=0.10.6
BUILDLINK_PKGSRCDIR.hs-cmdargs?=	../../wip/hs-cmdargs

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_CMDARGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cmdargs
