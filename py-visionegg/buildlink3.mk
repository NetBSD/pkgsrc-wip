# $NetBSD: buildlink3.mk,v 1.1 2004/05/10 01:40:50 blef Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_VISIONEGG_BUILDLINK3_MK:=	${PY_VISIONEGG_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyvisionegg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyvisionegg}
BUILDLINK_PACKAGES+=	pyvisionegg

.if !empty(PY_VISIONEGG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyvisionegg+=	${PYPKGPREFIX}-visionegg>=0.9.9
BUILDLINK_PKGSRCDIR.pyvisionegg?=	../../wip/py-visionegg
.endif	# PY_VISIONEGG_BUILDLINK3_MK

.if exists(../../mk/opengl.buildlink3.mk)
# see PR 23845 for details
.include "../../mk/opengl.buildlink3.mk"
.else
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../wip/py-game/buildlink3.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
