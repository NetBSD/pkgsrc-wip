# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/23 13:07:02 mpasternak Exp $

.if !defined(PY_SCIPY_DISTUTILS_BUILDLINK2_MK)
PY_SCIPY_DISTUTILS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyscipy_distutils
BUILDLINK_DEPENDS.pyscipy_distutils?=	${PYPKGPREFIX}-scipy_distutils-*
BUILDLINK_PKGSRCDIR.pyscipy_distutils?=	../../wip/py-scipy_distutils

EVAL_PREFIX+=   	BUILDLINK_PREFIX.pyscipy_distutils=pyscipy_distutils
BUILDLINK_PREFIX.pyscipy_distutils_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyscipy_distutils=	# defined

BUILDLINK_TARGETS+=	pyscipy_distutils-buildlink

pyscipy_distutils-buildlink: _BUILDLINK_USE

.endif	# PY_SCIPY_DISTUTILS_BUILDLINK2_MK
