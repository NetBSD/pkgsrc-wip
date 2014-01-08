# $NetBSD: buildlink3.mk,v 1.1 2014/01/08 12:33:23 nsloss Exp $

BUILDLINK_TREE+=	emokit

.if !defined(EMOKIT_BUILDLINK3_MK)
EMOKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.emokit+=	emokit>=0.5
BUILDLINK_PKGSRCDIR.emokit?=	../../wip/emokit
.endif

BUILDLINK_TREE+=	-emokit
