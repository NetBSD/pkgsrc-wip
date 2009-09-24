# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/24 06:11:22 phonohawk Exp $

BUILDLINK_TREE+=	hs-terminfo

.if !defined(HS_TERMINFO_BUILDLINK3_MK)
HS_TERMINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-terminfo+=	hs-terminfo>=0.3.1.1
BUILDLINK_PKGSRCDIR.hs-terminfo?=	../../wip/hs-terminfo

.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.endif	# HS_TERMINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-terminfo
