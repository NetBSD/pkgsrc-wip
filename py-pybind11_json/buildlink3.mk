# $NetBSD: buildlink3.mk,v 1.5 2023/12/29 20:27:03 tnn Exp $

BUILDLINK_TREE+=	py-pybind11_json

.if !defined(PY_PYBIND11_JSON_BUILDLINK3_MK)
PY_PYBIND11_JSON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pybind11_json+=	${PYPKGPREFIX}-pybind11_json>=0.2.15
BUILDLINK_PKGSRCDIR.py-pybind11_json?=		../../wip/py-pybind11_json
BUILDLINK_DEPMETHOD.py-pybind11_json?=		build

.endif	# PY_PYBIND11_JSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pybind11_json
