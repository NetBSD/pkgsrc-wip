# $NetBSD: buildlink3.mk,v 1.18 2023/01/11 23:18:25 nikita Exp $

BUILDLINK_TREE+=	vde2

.if !defined(VDE2_BUILDLINK3_MK)
VDE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vde2+=	vde2>=2.3.3
BUILDLINK_ABI_DEPENDS.vde2+=	vde2>=2.3.3
BUILDLINK_PKGSRCDIR.vde2?=	../../wip/vde2

pkgbase := vde2

.endif # VDE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-vde2
