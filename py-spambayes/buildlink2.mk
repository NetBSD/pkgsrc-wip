# $NetBSD: buildlink2.mk,v 1.1 2004/01/04 10:23:30 mpasternak Exp $
#
# This Makefile fragment is included by packages that use py-spambayes.
#

.if !defined(PY_SPAMBAYES_BUILDLINK2_MK)
PY_SPAMBAYES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-spambayes
BUILDLINK_DEPENDS.${PYPKGPREFIX}-spambayes?=		${PYPKGPREFIX}-spambayes>=1.0a7
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-spambayes?=		../../wip/py-spambayes

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-spambayes=${PYPKGPREFIX}-spambayes
BUILDLINK_PREFIX.${PYPKGPREFIX}-spambayes_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-spambayes-buildlink

${PYPKGPREFIX}-spambayes-buildlink: _BUILDLINK_USE

.endif	# PY_SPAMBAYES_BUILDLINK2_MK
