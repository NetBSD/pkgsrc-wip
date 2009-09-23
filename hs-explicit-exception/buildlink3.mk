# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 06:48:34 phonohawk Exp $

BUILDLINK_TREE+=	hs-explicit-exception

.if !defined(HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK)
HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-explicit-exception+=	hs-explicit-exception>=0.1.4
BUILDLINK_PKGSRCDIR.hs-explicit-exception?=	../../wip/hs-explicit-exception

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-explicit-exception
