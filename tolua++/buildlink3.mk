# $NetBSD$

BUILDLINK_TREE+=	toluapp

.if !defined(TOLUAPP_BUILDLINK3_MK)
TOLUAPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.toluapp+=	tolua++>=1.0.93
BUILDLINK_ABI_DEPENDS.toluapp+=	tolua++>=1.0.93
BUILDLINK_PKGSRCDIR.toluapp?=	../../wip/tolua++

.include "../../lang/lua51/buildlink3.mk"
.endif # TOLUAPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-toluapp
