# $NetBSD: buildlink3.mk,v 1.1 2012/01/26 11:14:54 mwdavies Exp $

BUILDLINK_TREE+=	marble

.if !defined(MARBLE_BUILDLINK3_MK)
MARBLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.marble+=	marble>=4.8.0
BUILDLINK_PKGSRCDIR.marble?=	../../wip/marble

.include "../../wip/kdelibs4/buildlink3.mk"
.endif	# MARBLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-marble
