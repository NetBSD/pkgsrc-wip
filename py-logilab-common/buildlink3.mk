# $NetBSD: buildlink3.mk,v 1.2 2009/07/06 22:33:21 jihbed Exp $

BUILDLINK_TREE+=	py-logilab-common

.if !defined(PY_LOGILAB_COMMON_BUILDLINK3_MK)
PY_LOGILAB_COMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-logilab-common+=	${PYPKGPREFIX}-logilab-common>=0.42.0
BUILDLINK_ABI_DEPENDS.py-logilab-common+=	${PYPKGPREFIX}-logilab-common>=2.41.0
BUILDLINK_PKGSRCDIR.py-logilab-common?=	../../wip/py-logilab-common

.endif	# PY_LOGILAB_COMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-logilab-common
