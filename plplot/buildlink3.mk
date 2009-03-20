# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	plplot

.if !defined(PLPLOT_BUILDLINK3_MK)
PLPLOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plplot+=	plplot>=5.9.2
BUILDLINK_PKGSRCDIR.plplot?=	../../wip/plplot

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif # PLPLOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-plplot
