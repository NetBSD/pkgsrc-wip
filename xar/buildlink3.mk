# $NetBSD: buildlink3.mk,v 1.2 2006/12/02 17:22:52 dhowland Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XAR_BUILDLINK3_MK:=	${XAR_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xar
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxar}
BUILDLINK_PACKAGES+=	xar
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xar

.if ${XAR_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xar+=	xar>=1.4
BUILDLINK_PKGSRCDIR.xar?=	../../wip/xar
.endif	# XAR_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
