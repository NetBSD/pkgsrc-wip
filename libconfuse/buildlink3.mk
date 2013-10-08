# $NetBSD: buildlink3.mk,v 1.1 2013/10/08 02:02:04 makoto Exp $

BUILDLINK_TREE+=	libconfuse

.if !defined(LIBCONFUSE_BUILDLINK3_MK)
LIBCONFUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libconfuse+=	libconfuse>=2.7
BUILDLINK_PKGSRCDIR.libconfuse?=	../../wip/libconfuse

.endif # LIBCONFUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libconfuse
