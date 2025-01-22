# $NetBSD: buildlink3.mk,v 1.1 2012/11/12 23:26:27 christtrekker Exp $

BUILDLINK_TREE+=	edelib

.if !defined(EDELIB_BUILDLINK3_MK)
EDELIB_BUILDLINK3_MK:=

USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11

BUILDLINK_API_DEPENDS.edelib+=	edelib>=2.0
BUILDLINK_PKGSRCDIR.edelib?=	../../wip/edelib

.endif	# EDELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-edelib
