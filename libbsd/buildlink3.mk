# $NetBSD$

BUILDLINK_TREE+=	libbsd

.if !defined(LIBBSD_BUILDLINK3_MK)
LIBBSD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbsd+=	libbsd>=0.11.0
BUILDLINK_PKGSRCDIR.libbsd?=	../../devel/libbsd

BUILDLINK_CFLAGS.libbsd+=       -I${BUILDLINK_PREFIX.libbsd}/include/bsd -DLIBBSD_OVERLAY
BUILDLINK_LIBS.libbsd+=         -lbsd -lmd

.include "../../devel/libmd/buildlink3.mk"
.endif	# LIBBSD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbsd
