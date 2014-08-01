# $NetBSD: buildlink3.mk,v 1.5 2014/08/01 12:12:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ansi-wl-pprint

.if !defined(HS_ANSI_WL_PPRINT_BUILDLINK3_MK)
HS_ANSI_WL_PPRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-wl-pprint+=	hs-ansi-wl-pprint>=0.6.7
BUILDLINK_PKGSRCDIR.hs-ansi-wl-pprint?=	../../wip/hs-ansi-wl-pprint

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.endif	# HS_ANSI_WL_PPRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-wl-pprint
