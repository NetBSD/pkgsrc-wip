# $NetBSD: buildlink3.mk,v 1.2 2014/02/21 10:39:02 szptvlfn Exp $

BUILDLINK_TREE+=	hs-transformers-compat

.if !defined(HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK)
HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.1.1.1
BUILDLINK_PKGSRCDIR.hs-transformers-compat?=	../../wip/hs-transformers-compat

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers-compat
