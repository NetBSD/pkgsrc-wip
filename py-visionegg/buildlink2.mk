# $NetBSD: buildlink2.mk,v 1.2 2004/01/10 17:48:39 cjep Exp $
#
# This Makefile fragment is included by packages that use py-visionegg.
#

.if !defined(PY_VISIONEGG_BUILDLINK2_MK)
PY_VISIONEGG_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-visionegg
BUILDLINK_DEPENDS.${PYPKGPREFIX}-visionegg?=		${PYPKGPREFIX}-visionegg>=0.9.9
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-visionegg?=		../../wip/py-visionegg

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-visionegg=${PYPKGPREFIX}-visionegg
BUILDLINK_PREFIX.${PYPKGPREFIX}-visionegg_DEFAULT=	${LOCALBASE}

.if exists(../../mk/opengl.buildlink2.mk)
# see PR 23845 for details
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/MesaLib/buildlink2.mk"
.endif
.include "../../wip/py-game/buildlink2.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-visionegg-buildlink

${PYPKGPREFIX}-visionegg-buildlink: _BUILDLINK_USE

.endif	# PY_VISIONEGG_BUILDLINK2_MK
