# $NetBSD: buildlink3.mk,v 1.6 2014/08/03 22:16:39 thomasklausner Exp $

BUILDLINK_TREE+=	webkit-sharp

.if !defined(WEBKIT_SHARP_BUILDLINK3_MK)
WEBKIT_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-sharp+=	webkit-sharp>=0.2
BUILDLINK_ABI_DEPENDS.webkit-sharp?=	webkit-sharp>=0.3nb1
BUILDLINK_PKGSRCDIR.webkit-sharp?=	../../wip/webkit-sharp

.include "../../www/webkit1-gtk/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.endif # WEBKIT_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-sharp
