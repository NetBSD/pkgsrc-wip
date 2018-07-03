# $NetBSD: buildlink3.mk,v 1.9 2015/07/13 15:11:46 thomasklausner Exp $

BUILDLINK_TREE+=	py-webkitgtk

.if !defined(PY_WEBKITGTK_BUILDLINK3_MK)
PY_WEBKITGTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-webkitgtk+=	${PYPKGPREFIX}-webkitgtk>=1.1.6
BUILDLINK_ABI_DEPENDS.py-webkitgtk?=	${PYPKGPREFIX}-webkitgtk>=1.1.7nb1
BUILDLINK_PKGSRCDIR.py-webkitgtk?=	../../wip/py-webkit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit24-gtk/buildlink3.mk"
.endif	# PY_WEBKITGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-webkitgtk
