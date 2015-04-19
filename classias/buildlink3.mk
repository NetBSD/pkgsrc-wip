# $NetBSD: buildlink3.mk,v 1.1 2015/04/19 16:55:50 cheusov Exp $

BUILDLINK_TREE+=	classias

.if !defined(CLASSIAS_BUILDLINK3_MK)
CLASSIAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.classias+=	classias>=0.0.0
BUILDLINK_PKGSRCDIR.classias?=	../../wip/classias
.endif # CLASSIAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-classias
