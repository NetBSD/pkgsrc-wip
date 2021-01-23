# $NetBSD$
BUILDLINK_TREE+=	FNA3D

.if !defined(FNA3D_BUILDLINK3_MK)
FNA3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.FNA3D+=	FNA3D>=21.01
BUILDLINK_PKGSRCDIR.FNA3D?=	../../wip/fna3d

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mojoshader/buildlink3.mk"
.endif	# FNA3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-FNA3D
