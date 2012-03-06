# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/06 09:58:51 ftigeot Exp $

BUILDLINK_TREE+=	libmythes

.if !defined(LIBMYTHES_BUILDLINK3_MK)
LIBMYTHES_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libmythes+=	libmythes>=1.2.2
BUILDLINK_PKGSRCDIR.libmythes?=	../../wip/libmythes
.endif

BUILDLINK_TREE+=	-libmythes
