# $NetBSD: buildlink3.mk,v 1.1 2011/05/13 23:25:16 mwdavies Exp $

BUILDLINK_TREE+=	kdeutils4

.if !defined(KDEUTILS4_BUILDLINK3_MK)
KDEUTILS4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdeutils4+=	kdeutils4>=4.5.2
BUILDLINK_PKGSRCDIR.kdeutils4?=	../../wip/kdeutils4

.endif	# KDEUTILS4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdeutils4
