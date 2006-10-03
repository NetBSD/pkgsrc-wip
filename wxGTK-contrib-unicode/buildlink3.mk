# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/03 15:16:26 milosn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK:=	${WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wxGTK-contrib-unicode
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NwxGTK-contrib-unicode}
BUILDLINK_PACKAGES+=	wxGTK-contrib-unicode
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}wxGTK-contrib-unicode

.if !empty(WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.wxGTK-contrib-unicode+=	wxGTK-contrib-unicode>=2.6.0
BUILDLINK_ABI_DEPENDS.wxGTK-contrib-unicode?=	wxGTK-contrib-unicode>=2.6.3
BUILDLINK_PKGSRCDIR.wxGTK-contrib-unicode?=	../../wip/wxGTK-contrib-unicode

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/wxGTK-unicode/buildlink3.mk"

.endif	# WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
