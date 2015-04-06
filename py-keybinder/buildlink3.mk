# $NetBSD: buildlink3.mk,v 1.2 2015/04/06 09:53:21 krytarowski Exp $

BUILDLINK_TREE+=	py-keybinder

.if !defined(PY_KEYBINDER_BUILDLINK3_MK)
PY_KEYBINDER_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-keybinder+=	${PYPKGPREFIX}-keybinder>=0.3.0
BUILDLINK_PKGSRCDIR.py-keybinder?=	../../wip/py-keybinder

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../wip/keybinder/buildlink3.mk"
.endif	# PY_KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-keybinder
