# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/01/04 10:47:24 mpasternak Exp $
#
# This Makefile fragment is included by packages that use ${PYPKGPREFIX}-mmpython.
#

.if !defined(PY_MMPYTHON_BUILDLINK2_MK)
PY_MMPYTHON_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-mmpython
BUILDLINK_DEPENDS.${PYPKGPREFIX}-mmpython?=		${PYPKGPREFIX}-mmpython>=0.3
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-mmpython?=		../../wip/py-mmpython

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-mmpython=${PYPKGPREFIX}-mmpython
BUILDLINK_PREFIX.${PYPKGPREFIX}-mmpython_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-mmpython-buildlink

${PYPKGPREFIX}-mmpython-buildlink: _BUILDLINK_USE

.endif	# PY_MMPYTHON_BUILDLINK2_MK
