# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/03 15:14:59 milosn Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WXGTK_UNICODE_BUILDLINK3_MK:=	${WXGTK_UNICODE_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK-unicode
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK-unicode}
BUILDLINK_PACKAGES+=	wxGTK-unicode
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wxGTK-unicode

.if !empty(WXGTK_UNICODE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.wxGTK-unicode+=	wxGTK-unicode>=2.6.0
BUILDLINK_ABI_DEPENDS.wxGTK-unicode?=	wxGTK-unicode>=2.6.3
BUILDLINK_PKGSRCDIR.wxGTK-unicode?=	../../wip/wxGTK-unicode
.endif	# WXGTK_UNICODE_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
