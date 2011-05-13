# $NetBSD: buildlink3.mk,v 1.2 2011/05/13 11:02:56 ryo-on Exp $

BUILDLINK_TREE+=	gmock

.if !defined(GMOCK_BUILDLINK3_MK)
GMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmock+=	gmock>=1.6.0
BUILDLINK_PKGSRCDIR.gmock?=	../../wip/gmock

.include "../../devel/googletest/buildlink3.mk"
.endif	# GMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmock
