# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libexosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexosip2+=	libeXosip2>=3.2.0
BUILDLINK_PKGSRCDIR.libexosip2?=	../../wip/libexosip
.endif # LIBEXOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexosip2
