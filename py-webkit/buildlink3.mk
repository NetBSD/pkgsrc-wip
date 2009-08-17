# $NetBSD: buildlink3.mk,v 1.5 2009/08/17 20:50:34 jihbed Exp $

BUILDLINK_TREE+=	py-webkitgtk

.if !defined(PY_WEBKITGTK_BUILDLINK3_MK)
PY_WEBKITGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-webkitgtk+=	${PYPKGPREFIX}-webkitgtk>=1.1.6
BUILDLINK_PKGSRCDIR.py-webkitgtk?=	../../wip/py-webkit


.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.endif	# PY_WEBKITGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-webkitgtk
