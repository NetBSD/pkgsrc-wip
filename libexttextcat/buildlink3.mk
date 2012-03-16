# $NetBSD: buildlink3.mk,v 1.2 2012/03/16 11:47:22 thomasklausner Exp $

BUILDLINK_TREE+=	libexttextcat

.if !defined(LIBEXTTEXTCAT_BUILDLINK3_MK)
LIBEXTTEXTCAT_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libexttextcat+=	libexttextcat>=3.2
BUILDLINK_PKGSRCDIR.libexttextcat?=	../../wip/libexttextcat
.endif

BUILDLINK_TREE+=	-libexttextcat
