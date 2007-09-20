# $NetBSD: buildlink3.mk,v 1.9 2007/09/20 21:37:24 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EVAS_BUILDLINK3_MK:=	${EVAS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	evas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevas}
BUILDLINK_PACKAGES+=	evas
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evas

.if ${EVAS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.037
BUILDLINK_PKGSRCDIR.evas?=	../../wip/evas
.endif	# EVAS_BUILDLINK3_MK

.include	"../../wip/eet/buildlink3.mk"
.include	"../../graphics/librsvg/buildlink3.mk"
.include	"../../graphics/libungif/buildlink3.mk"
.include	"../../graphics/freetype2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
