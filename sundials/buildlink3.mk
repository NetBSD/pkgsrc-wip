# $NetBSD$

BUILDLINK_TREE+=	sundials

.if !defined(SUNDIALS_BUILDLINK3_MK)
SUNDIALS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sundials+=	sundials>=7.1.1
BUILDLINK_ABI_DEPENDS.sundials+=	sundials>=7.1.1
BUILDLINK_PKGSRCDIR.sundials?=		../../wip/sundials
.endif	# SUNDIALS_BUILDLINK3_MK

BUILDLINK_TREE+=	-sundials
