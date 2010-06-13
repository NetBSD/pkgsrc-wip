# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:47:21 thomasklausner Exp $

BUILDLINK_TREE+=	wxGTK-contrib-unicode

.if !defined(WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK)
WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wxGTK-contrib-unicode+=	wxGTK-contrib-unicode>=2.8.0
BUILDLINK_ABI_DEPENDS.wxGTK-contrib-unicode?=	wxGTK-contrib-unicode>=2.8.8nb1
BUILDLINK_PKGSRCDIR.wxGTK-contrib-unicode?=	../../wip/wxGTK-contrib-unicode

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/wxGTK-unicode/buildlink3.mk"
.endif # WXGTK_CONTRIB_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-wxGTK-contrib-unicode
