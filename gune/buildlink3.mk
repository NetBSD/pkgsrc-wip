# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	gune

.if !defined(GUNE_BUILDLINK3_MK)
GUNE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gune+=	gune>=1.0
BUILDLINK_PKGSRCDIR.gune?=	../../wip/gune
.endif # GUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gune
