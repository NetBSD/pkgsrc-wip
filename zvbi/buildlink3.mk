# $NetBSD: buildlink3.mk,v 1.7 2009/06/02 14:39:03 noud4 Exp $

BUILDLINK_TREE+=	zvbi

.if !defined(ZVBI_BUILDLINK3_MK)
ZVBI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zvbi+=	zvbi>=0.2.16
BUILDLINK_PKGSRCDIR.zvbi?=	../../wip/zvbi

.include "../../textproc/libunicode/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif # X11_TYPE
.endif # ZVBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-zvbi
