# $NetBSD: buildlink3.mk,v 1.1 2012/09/17 22:24:25 jihbed Exp $

BUILDLINK_TREE+=	mce

.if !defined(MCE_BUILDLINK3_MK)
MCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mce+=	mce>=1.5.6
BUILDLINK_PKGSRCDIR.mce?=	../../wip/mce
.endif	# MCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-mce
