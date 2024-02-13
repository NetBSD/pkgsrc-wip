# $NetBSD: buildlink3.mk,v 1.0 2023/12/27 13:30:00 dkazankov Exp $

BUILDLINK_TREE+=	alire

.if !defined(ALIRE_BUILDLINK3_MK)
ALIRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alire+=	alire>=2.0
BUILDLINK_ABI_DEPENDS.alire+=	alire>=2.0.0
BUILDLINK_PKGSRCDIR.alire=	../../wip/alire
BUILDLINK_DEPMETHOD.alire?=	build

.endif

BUILDLINK_TREE+=	-alire
