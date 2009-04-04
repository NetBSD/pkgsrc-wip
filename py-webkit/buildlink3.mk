# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/04 14:48:17 jihbed Exp $
#

BUILDLINK_TREE+=	py25-webkitgtk

.if !defined(PY25_WEBKITGTK_BUILDLINK3_MK)
PY25_WEBKITGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py25-webkitgtk+=	py25-webkitgtk>=1.1.4
BUILDLINK_PKGSRCDIR.py25-webkitgtk?=	../../category/py-webkit

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.endif	# PY25_WEBKITGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py25-webkitgtk
