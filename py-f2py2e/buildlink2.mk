# $NetBSD: buildlink2.mk,v 1.1 2003/11/23 13:08:21 mpasternak Exp $

.if !defined(PY_F2PY2E_BUILDLINK2_MK)
PY_F2PY2E_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"
.include "../../wip/py-scipy_distutils/buildlink2.mk"

BUILDLINK_PACKAGES+=		pyf2py2e
BUILDLINK_DEPENDS.pyf2py2e?=	${PYPKGPREFIX}-f2py2e-*
BUILDLINK_PKGSRCDIR.pyf2py2e?=	../../wip/py-f2py2e

EVAL_PREFIX+=   	BUILDLINK_PREFIX.pyf2py2e=pyf2py2e
BUILDLINK_PREFIX.pyf2py2e_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyf2py2e=	${PYSITELIB}/f2py2e/src/*

BUILDLINK_TARGETS+=	pyf2py2e-buildlink

pyf2py2e-buildlink: _BUILDLINK_USE

.endif	# PY_F2PY2E_BUILDLINK2_MK
