# $NetBSD$
BUILDLINK_TREE+=	fna

.if !defined(FNA_BUILDLINK3_MK)
FNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fna+=	fna>=21.01
BUILDLINK_PKGSRCDIR.fna?=	../../wip/fna

.include "../../wip/mojoshader/buildlink3.mk"
.include "../../wip/fna3d/buildlink3.mk"
.include "../../lang/mono6/buildlink3.mk"
.endif	# FNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-fna
