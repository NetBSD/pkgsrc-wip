# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/26 18:40:55 marc Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WXGTK_CONTRIB_BUILDLINK3_MK:=	${WXGTK_CONTRIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK-contrib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK-contrib}
BUILDLINK_PACKAGES+=	wxGTK-contrib

.if !empty(WXGTK_CONTRIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wxGTK-contrib+=	wxGTK-contrib>=2.5.1
BUILDLINK_PKGSRCDIR.wxGTK-contrib?=	../../wip/wxgtk-devel-contrib
.endif	# WXGTK_CONTRIB_BUILDLINK3_MK

.include "../../wip/wxgtk-devel/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
