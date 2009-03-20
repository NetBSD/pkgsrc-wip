# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	kdebase-runtime

.if !defined(KDEBASE_RUNTIME_BUILDLINK3_MK)
KDEBASE_RUNTIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebase-runtime+=	kdebase-runtime4>=4.0.0
BUILDLINK_ABI_DEPENDS.kdebase-runtime?=	kdebase-runtime4>=4.0.0nb1
BUILDLINK_PKGSRCDIR.kdebase-runtime?=	../../wip/kdebase-runtime4

.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdepimlibs4/buildlink3.mk"
.endif # KDEBASE_RUNTIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebase-runtime
