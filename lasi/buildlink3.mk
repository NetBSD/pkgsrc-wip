# $NetBSD: buildlink3.mk,v 1.2 2010/06/13 22:47:10 thomasklausner Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBLASI_BUILDLINK3_MK:=	${LIBLASI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	liblasi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nliblasi}
BUILDLINK_PACKAGES+=	liblasi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}liblasi

.if ${LIBLASI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.liblasi+=	liblasi>=1.1.0
BUILDLINK_ABI_DEPENDS.liblasi?=	liblasi>=1.1.0nb1
BUILDLINK_PKGSRCDIR.liblasi?=	../../wip/lasi
.endif	# LIBLASI_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
