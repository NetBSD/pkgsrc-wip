# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/03/17 11:03:23 jihbed Exp $
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTKHOTKEY_BUILDLINK3_MK:=	${GTKHOTKEY_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gtkhotkey
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkhotkey}
BUILDLINK_PACKAGES+=	gtkhotkey
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtkhotkey

.if ${GTKHOTKEY_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gtkhotkey+=	gtkhotkey>=0.2.0
BUILDLINK_PKGSRCDIR.gtkhotkey?=	../../wip/gtkhotkey
.endif	# GTKHOTKEY_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
