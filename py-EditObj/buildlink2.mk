# $NetBSD: buildlink2.mk,v 1.1 2004/01/02 03:13:38 mpasternak Exp $
#
# This Makefile fragment is included by packages that use py-EditObj.
#

.if !defined(PY_EDITOBJ_BUILDLINK2_MK)
PY_EDITOBJ_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-EditObj
BUILDLINK_DEPENDS.${PYPKGPREFIX}-EditObj?=		${PYPKGPREFIX}-EditObj>=0.5.3
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-EditObj?=		../../wip/py-EditObj

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-EditObj=${PYPKGPREFIX}-EditObj
BUILDLINK_PREFIX.${PYPKGPREFIX}-EditObj_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-EditObj-buildlink

${PYPKGPREFIX}-EditObj-buildlink: _BUILDLINK_USE

.endif	# PY_EDITOBJ_BUILDLINK2_MK
