# $NetBSD: buildlink3.mk,v 1.1 2012/01/23 00:30:35 mwdavies Exp $

BUILDLINK_TREE+=	kde-workspace

.if !defined(KDE_WORKSPACE_BUILDLINK3_MK)
KDE_WORKSPACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-workspace+=	kde-workspace4>=4.0.0
BUILDLINK_ABI_DEPENDS.kde-workspace?=	kde-workspace4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kde-workspace?=	../../wip/kde-workspace4

.include "../../graphics/qimageblitz/buildlink3.mk"
.include "../../wip/kdelibs4/buildlink3.mk"
.endif # KDE_WORKSPACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-workspace
