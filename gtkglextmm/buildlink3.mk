# $NetBSD: buildlink3.mk,v 1.2 2010/08/11 11:00:39 jihbed Exp $

BUILDLINK_TREE+=	gtkglextmm

.if !defined(GTKGLEXTMM_BUILDLINK3_MK)
GTKGLEXTMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkglextmm+=	gtkglextmm>=1.2.0
BUILDLINK_PKGSRCDIR.gtkglextmm?=	../../wip/gtkglextmm

.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif	# GTKGLEXTMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkglextmm
