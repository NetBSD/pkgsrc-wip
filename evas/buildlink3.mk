# $NetBSD: buildlink3.mk,v 1.8 2007/04/29 12:50:22 grzela1 Exp $

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
.include	"../../graphics/librsvg2/buildlink3.mk"
.include	"../../graphics/libungif/buildlink3.mk"
.include	"../../graphics/freetype2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
