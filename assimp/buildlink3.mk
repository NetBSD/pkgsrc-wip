# $NetBSD$

BUILDLINK_TREE+=	assimp

.if !defined(ASSIMP_BUILDLINK3_MK)
ASSIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.assimp+=	assimp>=0
BUILDLINK_ABI_DEPENDS.assimp+=	assimp>=0
BUILDLINK_PKGSRCDIR.assimp?=	../../wip/assimp

.include "../../devel/zlib/buildlink3.mk"
.endif # ASSIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-assimp
