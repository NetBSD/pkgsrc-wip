# $NetBSD: buildlink3.mk,v 1.4 2011/05/13 23:25:14 mwdavies Exp $

BUILDLINK_TREE+=	kdebase4

.if !defined(KDEBASE4_BUILDLINK3_MK)
KDEBASE4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase4+=	kdebase4>=4.1.85
BUILDLINK_PKGSRCDIR.kdebase4?=	../../wip/kdebase4
.endif # KDEBASE4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase4
