# $NetBSD$

BUILDLINK_TREE+=	libgamemusic

.if !defined(LIBGAMEMUSIC_BUILDLINK3_MK)
LIBGAMEMUSIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgamemusic+=	libgamemusic>=1.2
BUILDLINK_PKGSRCDIR.libgamemusic?=	../../wip/libgamemusic

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# LIBGAMEMUSIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgamemusic
