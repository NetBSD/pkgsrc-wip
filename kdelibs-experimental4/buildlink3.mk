# $NetBSD: buildlink3.mk,v 1.1 2009/07/30 12:08:27 mwdavies Exp $

BUILDLINK_TREE+=	kdelibs-experimental4

.if !defined(KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK)
KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdelibs-experimental4+=	kdelibs-experimental4>=4.2.98
BUILDLINK_PKGSRCDIR.kdelibs-experimental4?=	../../wip/kdelibs-experimental4

.include "../../wip/kdelibs4/buildlink3.mk"
.endif	# KDELIBS_EXPERIMENTAL4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdelibs-experimental4
