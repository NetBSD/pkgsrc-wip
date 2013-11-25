# $NetBSD: buildlink3.mk,v 1.1 2013/11/25 11:31:34 szptvlfn Exp $

BUILDLINK_TREE+=	hs-http-types

.if !defined(HS_HTTP_TYPES_BUILDLINK3_MK)
HS_HTTP_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-http-types+=	hs-http-types>=0.8.2
BUILDLINK_PKGSRCDIR.hs-http-types?=	../../wip/hs-http-types

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-case-insensitive/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_HTTP_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-http-types
