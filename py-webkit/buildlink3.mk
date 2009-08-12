# $NetBSD: buildlink3.mk,v 1.4 2009/08/12 02:32:03 obache Exp $

BUILDLINK_TREE+=	py-webkitgtk

.if !defined(PY_WEBKITGTK_BUILDLINK3_MK)
PY_WEBKITGTK_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-webkitgtk+=	${PYPKGPREFIX}-webkitgtk>=1.1.4
BUILDLINK_ABI_DEPENDS.py-webkitgtk?=	py25-webkitgtk>=1.1.5nb1
BUILDLINK_PKGSRCDIR.py-webkitgtk?=	../../wip/py-webkit

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.endif	# PY_WEBKITGTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-webkitgtk
