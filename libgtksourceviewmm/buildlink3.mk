# $NetBSD: buildlink3.mk,v 1.2 2008/01/18 04:30:15 tnn2 Exp $

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
BUILDLINK_ABI_DEPENDS.libgtksourceviewmm?=	libgtksourceviewmm>=0.3.1nb2
BUILDLINK_PKGSRCDIR.libgtksourceviewmm?=	../../wip/libgtksourceviewmm
.endif	# LIBGTKSOURCEVIEWMM_BUILDLINK3_MK

.include "../../x11/gtksourceview/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
