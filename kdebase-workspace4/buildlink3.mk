# $NetBSD: buildlink3.mk,v 1.7 2011/05/13 23:25:14 mwdavies Exp $

BUILDLINK_TREE+=	kdebase-workspace

.if !defined(KDEBASE_WORKSPACE_BUILDLINK3_MK)
KDEBASE_WORKSPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase-workspace+=	kdebase-workspace4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-workspace?=	kdebase-workspace4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kdebase-workspace?=	../../wip/kdebase-workspace4

.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.endif # KDEBASE_WORKSPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase-workspace
