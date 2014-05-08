# $NetBSD: buildlink3.mk,v 1.3 2014/05/08 00:31:52 szptvlfn Exp $

BUILDLINK_TREE+=	hs-transformers-compat

.if !defined(HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK)
HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.3
BUILDLINK_PKGSRCDIR.hs-transformers-compat?=	../../wip/hs-transformers-compat

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers-compat
