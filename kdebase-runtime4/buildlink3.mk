# $NetBSD: buildlink3.mk,v 1.6 2011/05/13 23:25:14 mwdavies Exp $

BUILDLINK_TREE+=	kdebase-runtime

.if !defined(KDEBASE_RUNTIME_BUILDLINK3_MK)
KDEBASE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase-runtime+=	kdebase-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-runtime?=	kdebase-runtime4>=4.5.4nb1
BUILDLINK_PKGSRCDIR.kdebase-runtime?=	../../wip/kdebase-runtime4

.include "../../wip/kdelibs4/buildlink3.mk"
.endif # KDEBASE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase-runtime
