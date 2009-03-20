# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libargp

.if !defined(LIBARGP_BUILDLINK3_MK)
LIBARGP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libargp+=	libargp>=1.3
BUILDLINK_PKGSRCDIR.libargp?=	../../wip/libargp
BUILDLINK_DEPMETHOD.libargp?=	build
.endif # LIBARGP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libargp
