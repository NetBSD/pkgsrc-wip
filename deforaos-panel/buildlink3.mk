# $NetBSD: buildlink3.mk,v 1.3 2012/12/24 03:44:13 khorben Exp $
#

BUILDLINK_TREE+=	deforaos-panel

.if !defined(DEFORAOS_PANEL_BUILDLINK3_MK)
DEFORAOS_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-panel+=	deforaos-panel>=0.2.12
BUILDLINK_PKGSRCDIR.deforaos-panel?=	../../wip/deforaos-panel

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# DEFORAOS_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-panel
