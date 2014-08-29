# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:12 szptvlfn Exp $

BUILDLINK_TREE+=	hs-explicit-exception

.if !defined(HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK)
HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-explicit-exception+=	hs-explicit-exception>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-explicit-exception+=	hs-explicit-exception>=0.1.6
BUILDLINK_PKGSRCDIR.hs-explicit-exception?=	../../wip/hs-explicit-exception

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-explicit-exception
