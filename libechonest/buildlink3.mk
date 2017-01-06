# $NetBSD$
BUILDLINK_TREE+=	libechonest

.if !defined(LIBECHONEST_BUILDLINK3_MK)
LIBECHONEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libechonest+=	libechonest>=2.3.1
BUILDLINK_PKGSRCDIR.libechonest?=	../../local/libechonest
.endif	# LIBECHONEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-libechonest
