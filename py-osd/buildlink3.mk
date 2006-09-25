# $NetBSD: buildlink3.mk,v 1.4 2006/09/25 12:38:59 dhowland Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_OSD_BUILDLINK3_MK:=	${PY_OSD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-osd
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-osd}
BUILDLINK_PACKAGES+=	py-osd
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-osd

.if ${PY_OSD_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-osd+=	${PYPKGPREFIX}-osd>=0.2.14
BUILDLINK_PKGSRCDIR.py-osd?=	../../wip/py-osd
.endif	# PY_OSD_BUILDLINK3_MK

.include "../../x11/xosd/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
