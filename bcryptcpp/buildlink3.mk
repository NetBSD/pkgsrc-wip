# $NetBSD$

BUILDLINK_TREE+=	bcryptcpp

.if !defined(BCRYPTCPP_BUILDLINK3_MK)
BCRYPTCPP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.bcryptcpp?=	build

BUILDLINK_API_DEPENDS.bcryptcpp+=	bcryptcpp>=2.0
BUILDLINK_PKGSRCDIR.bcryptcpp?=		../../wip/bcryptcpp
.endif	# BCRYPTCPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-bcryptcpp
