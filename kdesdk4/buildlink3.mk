# $NetBSD: buildlink3.mk,v 1.1 2011/05/13 23:25:16 mwdavies Exp $

BUILDLINK_TREE+=	kdesdk4

.if !defined(KDESDK4_BUILDLINK3_MK)
KDESDK4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdesdk4+=	kdesdk4>=4.6.2
BUILDLINK_PKGSRCDIR.kdesdk4?=	../../wip/kdesdk4

.endif	# KDESDK4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdesdk4
