# $NetBSD$

BUILDLINK_DEPMETHOD.opencl-clhpp?=	build

BUILDLINK_TREE+=	opencl-clhpp

.if !defined(OPENCL_CLHPP_BUILDLINK3_MK)
OPENCL_CLHPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencl-clhpp+=	opencl-clhpp>=2.2.0.20200123
BUILDLINK_PKGSRCDIR.opencl-clhpp?=	../../wip/opencl-clhpp

.endif	# OPENCL_CLHPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-clhpp
