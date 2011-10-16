# $NetBSD: buildlink3.mk,v 1.1 2011/10/16 21:24:05 ftigeot Exp $

BUILDLINK_TREE+=	libexttextcat

.if !defined(LIBEXTTEXTCAT_BUILDLINK3_MK)
LIBEXTTEXTCAT_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libexttextcat+=	libexttextcat>=2.2
BUILDLINK_PKGSRCDIR.libexttextcat?=	../../wip/libexttextcat
.endif

BUILDLINK_TREE+=	-libexttextcat
