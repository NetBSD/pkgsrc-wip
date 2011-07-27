# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/27 05:52:11 phonohawk Exp $

BUILDLINK_TREE+=	hs-hxt-unicode

.if !defined(HS_HXT_UNICODE_BUILDLINK3_MK)
HS_HXT_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-unicode+=	hs-hxt-unicode>=9.0
BUILDLINK_PKGSRCDIR.hs-hxt-unicode?=	../../wip/hs-hxt-unicode

.include "../../wip/hs-hxt-charproperties/buildlink3.mk"
.endif	# HS_HXT_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-unicode
