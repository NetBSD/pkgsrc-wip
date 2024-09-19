# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vte

.if !defined(HS_VTE_BUILDLINK3_MK)
HS_VTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vte+=	hs-vte>=0.12.1
BUILDLINK_ABI_DEPENDS.hs-vte+=	hs-vte>=0.12.1
BUILDLINK_PKGSRCDIR.hs-vte?=	../../wip/hs-vte

.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-gtk/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../x11/vte/buildlink3.mk"
.endif	# HS_VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vte
