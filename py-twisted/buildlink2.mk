# $NetBSD: buildlink2.mk,v 1.1 2004/01/04 10:18:52 mpasternak Exp $
#
# This Makefile fragment is included by packages that use py-twisted.
#

.if !defined(PY_TWISTED_BUILDLINK2_MK)
PY_TWISTED_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-twisted
BUILDLINK_DEPENDS.${PYPKGPREFIX}-Twisted?=		${PYPKGPREFIX}-twisted>=1.1.1
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-Twisted?=		../../wip/py-twisted

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-Twisted=${PYPKGPREFIX}-twisted
BUILDLINK_PREFIX.${PYPKGPREFIX}-Twisted_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-Twisted-buildlink

${PYPKGPREFIX}-Twisted-buildlink: _BUILDLINK_USE

.endif	# PY_TWISTED_BUILDLINK2_MK
