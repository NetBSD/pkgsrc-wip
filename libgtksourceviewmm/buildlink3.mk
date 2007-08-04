# $NetBSD: buildlink3.mk,v 1.1 2007/08/04 09:54:46 makoto Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
LIBGTKSOURCEVIEWMM_BUILDLINK3_MK:=	${LIBGTKSOURCEVIEWMM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libgtksourceviewmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgtksourceviewmm}
BUILDLINK_PACKAGES+=	libgtksourceviewmm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgtksourceviewmm

.if ${LIBGTKSOURCEVIEWMM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libgtksourceviewmm+=	libgtksourceviewmm>=0.3.1
BUILDLINK_PKGSRCDIR.libgtksourceviewmm?=	../../wip/libgtksourceviewmm
.endif	# LIBGTKSOURCEVIEWMM_BUILDLINK3_MK

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
