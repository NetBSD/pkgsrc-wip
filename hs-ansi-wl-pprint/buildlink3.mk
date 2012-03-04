# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 08:53:39 phonohawk Exp $

BUILDLINK_TREE+=	hs-ansi-wl-pprint

.if !defined(HS_ANSI_WL_PPRINT_BUILDLINK3_MK)
HS_ANSI_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=0.6.4
BUILDLINK_PKGSRCDIR.hs-ansi-wl-pprint?=	../../wip/hs-ansi-wl-pprint

.include "../../wip/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_ANSI_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-wl-pprint
