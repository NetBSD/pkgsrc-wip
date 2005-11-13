# $NetBSD: buildlink3.mk,v 1.2 2005/11/13 06:26:38 dhowland Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_OSD_BUILDLINK3_MK:=	${PY_OSD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyosd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyosd}
BUILDLINK_PACKAGES+=	pyosd

.if !empty(PY_OSD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyosd+=	${PYPKGPREFIX}-osd>=0.2.14
BUILDLINK_PKGSRCDIR.pyosd?=	../../wip/py-osd

.include "../../x11/xosd/buildlink3.mk"

.endif	# PY_OSD_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
