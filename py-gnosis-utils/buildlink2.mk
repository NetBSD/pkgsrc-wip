# $NetBSD: buildlink2.mk,v 1.3 2003/07/27 17:24:50 marc Exp $

.if !defined(GNOSIS_UTILS_BUILDLINK2_MK)
GNOSIS_UTILS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			Gnosis-Utils
BUILDLINK_DEPENDS.Gnosis-Utils?=	${PYPKGPREFIX}-Gnosis-Utils>=1.1.0
BUILDLINK_PKGSRCDIR.Gnosis-Utils?=	../../wip/py-gnosis-utils

EVAL_PREFIX+=	BUILDLINK_PREFIX.Gnosis-Utils=${PYPKGPREFIX}-Gnosis-Utils
BUILDLINK_PREFIX.Gnosis-Utils_DEFAULT=	${LOCALBASE}

.include "../../textproc/pyxml/buildlink2.mk"

BUILDLINK_TARGETS+=	Gnosis-Utils-buildlink

Gnosis-Utils-buildlink: _BUILDLINK_USE

.endif	# GNOSIS_UTILS_BUILDLINK2_MK
