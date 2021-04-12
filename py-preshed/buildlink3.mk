# $NetBSD$
BUILDLINK_DEPMETHOD.preshed?=	build

BUILDLINK_TREE+=	preshed

.if !defined(PRESHED_BUILDLINK3_MK)
PRESHED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.preshed+=	preshed>=2.0.0nb1
BUILDLINK_PKGSRCDIR.preshed?=	../../wip/py-preshed
.endif	# PRESHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-preshed
