# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/25 17:12:28 marc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXGTK_BUILDLINK3_MK:=	${WXGTK_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK}
BUILDLINK_PACKAGES+=	wxGTK

.if !empty(WXGTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.wxGTK+=	wxGTK>=2.5.1
BUILDLINK_PKGSRCDIR.wxGTK?=	../../wip/wxgtk-devel
.endif	# WXGTK_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
.  include "../../x11/gtk/buildlink3.mk"
.else
.  include "../../x11/gtk2/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
