# $NetBSD: buildlink3.mk,v 1.1 2009/09/06 07:14:24 schnoebe Exp $

BUILDLINK_TREE+=	gloox

.if !defined(GLOOX_BUILDLINK3_MK)
GLOOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gloox+=	gloox>=1.0
BUILDLINK_PKGSRCDIR.gloox?=	../../wip/gloox

.endif # GLOOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gloox
