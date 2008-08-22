# $NetBSD: buildlink3.mk,v 1.1 2008/08/22 05:31:20 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTK2HS_BUILDLINK3_MK:=	${GTK2HS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gtk2hs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2hs}
BUILDLINK_PACKAGES+=	gtk2hs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gtk2hs

.if ${GTK2HS_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.gtk2hs?=	build
BUILDLINK_API_DEPENDS.gtk2hs+=	gtk2hs>=0.9.13
BUILDLINK_PKGSRCDIR.gtk2hs?=	../../wip/gtk2hs
.endif	# GTK2HS_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
