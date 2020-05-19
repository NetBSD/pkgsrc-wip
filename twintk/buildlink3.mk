# $NetBSD: buildlink3.mk,v 1.2 2013/08/14 01:33:35 outpaddling Exp $

BUILDLINK_TREE+=	twintk

.if !defined(TWINTK_BUILDLINK3_MK)
TWINTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twintk+=	twintk>=0.9.4
BUILDLINK_PKGSRCDIR.twintk?=	../../wip/twintk
BUILDLINK_DEPMETHOD.twintk?=	build
.endif	# TWINTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-twintk
