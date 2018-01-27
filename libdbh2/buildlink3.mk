# $NetBSD: buildlink3.mk,v 1.1 2015/01/17 02:05:16 makoto Exp $

BUILDLINK_TREE+=	libdbh2

.if !defined(LIBDBH2_BUILDLINK3_MK)
LIBDBH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbh2+=	libdbh2>=5.0.16
BUILDLINK_PKGSRCDIR.libdbh2?=	../../wip/libdbh2
.endif # LIBDBH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbh2
