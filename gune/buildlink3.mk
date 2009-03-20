# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	gune

BUILDLINK_API_DEPENDS.gune+=	gune>=1.0
BUILDLINK_PKGSRCDIR.gune?=	../../wip/gune
.endif # GUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gune
