# $NetBSD: buildlink3.mk,v 1.1 2012/07/26 20:47:09 ftigeot Exp $

BUILDLINK_TREE+=	libcmis

.if !defined(LIBCMIS_BUILDLINK3_MK)
LIBCMIS_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libcmis+=		libcmis>=0.2.3
BUILDLINK_PKGSRCDIR.libcmis?=		../../wip/libcmis
.endif

BUILDLINK_TREE+=	-libcmis
