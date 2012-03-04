# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 08:40:09 phonohawk Exp $

BUILDLINK_TREE+=	hs-explicit-exception

.if !defined(HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK)
HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-explicit-exception+=	hs-explicit-exception>=0.1.6
BUILDLINK_PKGSRCDIR.hs-explicit-exception?=	../../wip/hs-explicit-exception

.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_EXPLICIT_EXCEPTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-explicit-exception
