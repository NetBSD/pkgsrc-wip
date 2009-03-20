# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libharu

.if !defined(LIBHARU_BUILDLINK3_MK)
LIBHARU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libharu+=	libharu>=2.1.0
BUILDLINK_PKGSRCDIR.libharu?=	../../wip/libharu
.endif # LIBHARU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libharu
