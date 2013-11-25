# $NetBSD: buildlink3.mk,v 1.4 2013/11/25 10:54:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-case-insensitive

.if !defined(HS_CASE_INSENSITIVE_BUILDLINK3_MK)
HS_CASE_INSENSITIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-case-insensitive+=	hs-case-insensitive>=1.1.0.1
BUILDLINK_PKGSRCDIR.hs-case-insensitive?=	../../wip/hs-case-insensitive

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_CASE_INSENSITIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-case-insensitive
