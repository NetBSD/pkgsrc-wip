# $NetBSD: buildlink2.mk,v 1.1 2004/01/04 10:22:03 mpasternak Exp $
#
# This Makefile fragment is included by packages that use py23pth-bsddb.
#

.if !defined(PY_BSDDB_BUILDLINK2_MK)
PY_BSDDB_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-bsddb
BUILDLINK_DEPENDS.${PYPKGPREFIX}-bsddb?=		${PYPKGPREFIX}-bsddb>=0
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-bsddb?=		../../wip/py-bsddb

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-bsddb=${PYPKGPREFIX}-bsddb
BUILDLINK_PREFIX.${PYPKGPREFIX}-bsddb_DEFAULT=	${LOCALBASE}

.include "../../databases/db4/buildlink2.mk"

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-bsddb-buildlink

${PYPKGPREFIX}-bsddb-buildlink: _BUILDLINK_USE

.endif	# PY_BSDDB_BUILDLINK2_MK
