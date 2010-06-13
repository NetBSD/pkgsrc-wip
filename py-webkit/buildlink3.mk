# $NetBSD: buildlink3.mk,v 1.7 2010/06/13 22:47:14 thomasklausner Exp $

BUILDLINK_TREE+=	py-webkitgtk

.if !defined(PY_WEBKITGTK_BUILDLINK3_MK)
PY_WEBKITGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-webkitgtk+=	${PYPKGPREFIX}-webkitgtk>=1.1.6
BUILDLINK_ABI_DEPENDS.py-webkitgtk?=	${PYPKGPREFIX}-webkitgtk>=1.1.7nb1
BUILDLINK_PKGSRCDIR.py-webkitgtk?=	../../wip/py-webkit


.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.endif	# PY_WEBKITGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-webkitgtk
