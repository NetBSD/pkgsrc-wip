# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libopenmodeller

BUILDLINK_API_DEPENDS.libopenmodeller+=	libopenmodeller>=0.3.3
BUILDLINK_PKGSRCDIR.libopenmodeller?=	../../wip/openmodeller
.endif # LIBOPENMODELLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenmodeller
