# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	iksemel

.if !defined(IKSEMEL_BUILDLINK3_MK)
IKSEMEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iksemel+=	iksemel>=1.3
BUILDLINK_PKGSRCDIR.iksemel?=	../../wip/iksemel
.endif # IKSEMEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-iksemel
