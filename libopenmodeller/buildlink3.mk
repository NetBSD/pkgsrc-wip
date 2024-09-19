# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	libopenmodeller

.if !defined(LIBOPENMODELLER_BUILDLINK3_MK)
LIBOPENMODELLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenmodeller+=	libopenmodeller>=0.3.3
BUILDLINK_PKGSRCDIR.libopenmodeller?=	../../wip/openmodeller
.endif # LIBOPENMODELLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenmodeller
