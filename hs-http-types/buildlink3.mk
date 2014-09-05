# $NetBSD: buildlink3.mk,v 1.6 2014/09/05 21:39:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-http-types

.if !defined(HS_HTTP_TYPES_BUILDLINK3_MK)
HS_HTTP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-types+=	hs-http-types>=0.8.3
BUILDLINK_ABI_DEPENDS.hs-http-types+=	hs-http-types>=0.8.3
BUILDLINK_PKGSRCDIR.hs-http-types?=	../../wip/hs-http-types

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_HTTP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-types
