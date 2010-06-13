# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:47:21 thomasklausner Exp $

BUILDLINK_TREE+=	xfce4-radio-plugin

.if !defined(XFCE4_RADIO_PLUGIN_BUILDLINK3_MK)
XFCE4_RADIO_PLUGIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-radio-plugin+=	xfce4-radio-plugin>=0.2.0
BUILDLINK_ABI_DEPENDS.xfce4-radio-plugin?=	xfce4-radio-plugin>=0.2.0nb1
BUILDLINK_PKGSRCDIR.xfce4-radio-plugin?=	../../wip/xfce4-radio-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_RADIO_PLUGIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-radio-plugin
