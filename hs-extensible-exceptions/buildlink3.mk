# $NetBSD: buildlink3.mk,v 1.3 2013/03/02 10:48:16 phonohawk Exp $

BUILDLINK_TREE+=	hs-extensible-exceptions

.if !defined(HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK)
HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extensible-exceptions+=	hs-extensible-exceptions>=0.1.1
BUILDLINK_PKGSRCDIR.hs-extensible-exceptions?=	../../wip/hs-extensible-exceptions
.endif	# HS_EXTENSIBLE_EXCEPTIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extensible-exceptions
