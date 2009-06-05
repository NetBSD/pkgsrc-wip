# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/05 04:21:07 phonohawk Exp $

BUILDLINK_TREE+=	hs-extensible-exceptions

.if !defined(HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK)
HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensible-exceptions+=	hs-extensible-exceptions>=0.1.1.0
BUILDLINK_PKGSRCDIR.hs-extensible-exceptions?=	../../wip/hs-extensible-exceptions
.endif	# HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensible-exceptions
