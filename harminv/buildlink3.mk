# $NetBSD: buildlink3.mk,v 1.1 2011/04/30 22:07:07 jihbed Exp $

BUILDLINK_TREE+=	harminv

.if !defined(HARMINV_BUILDLINK3_MK)
HARMINV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harminv+=	harminv>=1.3.1
BUILDLINK_PKGSRCDIR.harminv?=	../../wip/harminv

.endif	# HARMINV_BUILDLINK3_MK

BUILDLINK_TREE+=	-harminv
