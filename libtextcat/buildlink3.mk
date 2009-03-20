# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libtextcat

.if !defined(LIBTEXTCAT_BUILDLINK3_MK)
LIBTEXTCAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtextcat+=	libtextcat>=2.2
BUILDLINK_PKGSRCDIR.libtextcat?=	../../category/libtextcat
.endif # LIBTEXTCAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtextcat
