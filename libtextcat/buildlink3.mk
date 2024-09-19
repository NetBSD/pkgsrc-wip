# $NetBSD: buildlink3.mk,v 1.3 2009/03/27 21:40:49 jihbed Exp $

BUILDLINK_TREE+=	libtextcat

.if !defined(LIBTEXTCAT_BUILDLINK3_MK)
LIBTEXTCAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtextcat+=	libtextcat>=2.2
BUILDLINK_PKGSRCDIR.libtextcat?=	../../wip/libtextcat
.endif # LIBTEXTCAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtextcat
