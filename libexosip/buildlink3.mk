# $NetBSD: buildlink3.mk,v 1.4 2011/02/19 17:14:58 gschwarz Exp $

BUILDLINK_TREE+=	libexosip2

.if !defined(LIBEXOSIP2_BUILDLINK3_MK)
LIBEXOSIP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libexosip2+=	libeXosip2>=3.5.0
BUILDLINK_PKGSRCDIR.libexosip2?=	../../wip/libexosip
.endif # LIBEXOSIP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libexosip2
