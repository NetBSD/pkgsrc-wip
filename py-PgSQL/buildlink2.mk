# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/05 21:46:29 marc Exp $

.include "../../lang/python/pyversion.mk"

.if !defined(PYPGSQL_BUILDLINK2_MK)
PYPGSQL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pyPgSQL
BUILDLINK_DEPENDS.pyPgSQL?=		${PYPKGPREFIX}-PgSQL>=2.3
BUILDLINK_PKGSRCDIR.pyPgSQL?=		../../wip/py-PgSQL

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyPgSQL=${PYPKGPREFIX}-PgSQL
BUILDLINK_PREFIX.pyPgSQL_DEFAULT=	${LOCALBASE}

.include "../../time/py-mxDateTime/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	pyPgSQL-buildlink

pyPgSQL-buildlink: _BUILDLINK_USE

.endif	# PYPGSQL_BUILDLINK2_MK
