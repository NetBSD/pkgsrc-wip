# $NetBSD: buildlink3.mk,v 1.4 2011/05/13 23:25:15 mwdavies Exp $

BUILDLINK_TREE+=	kdemultimedia4

.if !defined(KDEMULTIMEDIA4_BUILDLINK3_MK)
KDEMULTIMEDIA4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdemultimedia4+=	kdemultimedia4>=4.1.0
BUILDLINK_PKGSRCDIR.kdemultimedia4?=	../../wip/kdemultimedia4

.endif # KDEMULTIMEDIA4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdemultimedia4
