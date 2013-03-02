# $NetBSD: buildlink3.mk,v 1.3 2013/03/02 10:37:16 phonohawk Exp $

BUILDLINK_TREE+=	hs-ansi-wl-pprint

.if !defined(HS_ANSI_WL_PPRINT_BUILDLINK3_MK)
HS_ANSI_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=0.6.6
BUILDLINK_PKGSRCDIR.hs-ansi-wl-pprint?=	../../wip/hs-ansi-wl-pprint

.include "../../wip/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_ANSI_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-wl-pprint
