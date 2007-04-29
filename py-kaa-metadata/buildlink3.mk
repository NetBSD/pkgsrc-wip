# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/29 16:15:17 dhowland Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_KAA_METADATA_BUILDLINK3_MK:=	${PY_KAA_METADATA_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-kaa-metadata
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-kaa-metadata}
BUILDLINK_PACKAGES+=	py-kaa-metadata
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-kaa-metadata

.if ${PY_KAA_METADATA_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-kaa-metadata+=	${PYPKGPREFIX}-kaa-metadata>=0.6.1
BUILDLINK_PKGSRCDIR.py-kaa-metadata?=	../../wip/py-kaa-metadata
.endif	# PY_KAA_METADATA_BUILDLINK3_MK

.include "../../wip/py-kaa-base/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
