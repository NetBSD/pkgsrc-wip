# $NetBSD: buildlink3.mk,v 1.2 2009/09/24 09:32:19 phonohawk Exp $

BUILDLINK_TREE+=	hs-terminfo

.if !defined(HS_TERMINFO_BUILDLINK3_MK)
HS_TERMINFO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-terminfo+=	hs-terminfo>=0.3.1.1
BUILDLINK_PKGSRCDIR.hs-terminfo?=	../../wip/hs-terminfo

.include "../../devel/ncurses/buildlink3.mk"
.include "../../wip/hs-extensible-exceptions/buildlink3.mk"
.endif	# HS_TERMINFO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-terminfo
