# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:57 jsonn Exp $

BUILDLINK_TREE+=	zvbi

BUILDLINK_API_DEPENDS.zvbi+=	zvbi>=0.2.16
BUILDLINK_PKGSRCDIR.zvbi?=	../../wip/zvbi

.include "../../textproc/libunicode/buildlink3.mk"
.endif # ZVBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-zvbi
