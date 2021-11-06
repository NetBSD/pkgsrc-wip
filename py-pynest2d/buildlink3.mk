# $NetBSD$

BUILDLINK_TREE+=	py-pynest2d

.if !defined(PY_PYNEST2D_BUILDLINK3_MK)
PY_PYNEST2D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pynest2d+=	${PYPKGPREFIX}-pynest2d>=4.11.0
BUILDLINK_PKGSRCDIR.py-pynest2d?=	../../wip/py-pynest2d

.include "../../wip/libnest2d-ultimaker/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.endif	# PY_PYNEST2D_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pynest2d
