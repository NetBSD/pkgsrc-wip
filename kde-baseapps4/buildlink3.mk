# $NetBSD: buildlink3.mk,v 1.1 2012/01/23 10:02:30 mwdavies Exp $

BUILDLINK_TREE+=	kde-baseapps4

.if !defined(KDE_BASEAPPS4_BUILDLINK3_MK)
KDE_BASEAPPS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kde-baseapps4+=	kde-baseapps4>=4.1.85
BUILDLINK_PKGSRCDIR.kde-baseapps4?=	../../wip/kde-baseapps4
.endif # KDE_BASEAPPS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kde-baseapps4
