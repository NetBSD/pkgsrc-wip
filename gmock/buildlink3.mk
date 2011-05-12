# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/05/12 12:10:15 ryo-on Exp $

BUILDLINK_TREE+=	gmock

.if !defined(GMOCK_BUILDLINK3_MK)
GMOCK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gmock+=	gmock>=1.6.0
BUILDLINK_PKGSRCDIR.gmock?=	../../wip/gmock

.include "../../wip/gtest/buildlink3.mk"
.endif	# GMOCK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gmock
