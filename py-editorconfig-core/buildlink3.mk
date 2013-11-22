# $NetBSD: buildlink3.mk,v 1.1 2013/11/22 21:22:49 nros Exp $

BUILDLINK_TREE+=	py-editorconfig-core

.if !defined(PY_EDITORCONFIG_CORE_BUILDLINK3_MK)
PY_EDITORCONFIG_CORE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-editorconfig-core+=	${PYPKGPREFIX}-editorconfig-core>=0.11.1
BUILDLINK_PKGSRCDIR.py-editorconfig-core?=	../../wip/py-editorconfig-core
.endif	# PY_EDITORCONFIG_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-editorconfig-core
