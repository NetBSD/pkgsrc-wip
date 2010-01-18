# $NetBSD: buildlink3.mk,v 1.4 2010/01/18 09:38:35 thomasklausner Exp $

BUILDLINK_TREE+=	webkit-sharp

.if !defined(WEBKIT_SHARP_BUILDLINK3_MK)
WEBKIT_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-sharp+=	webkit-sharp>=0.2
BUILDLINK_ABI_DEPENDS.webkit-sharp?=	webkit-sharp>=0.2nb2
BUILDLINK_PKGSRCDIR.webkit-sharp?=	../../wip/webkit-sharp

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.endif # WEBKIT_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-sharp
