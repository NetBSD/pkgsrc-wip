# $NetBSD$

BUILDLINK_DEPMETHOD.opencl-headers?=	build

BUILDLINK_TREE+=	opencl-headers

.if !defined(OPENCL_HEADERS_BUILDLINK3_MK)
OPENCL_HEADERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencl-headers+=	opencl-headers>=2.2.0.20200123
BUILDLINK_PKGSRCDIR.opencl-headers?=	../../wip/opencl-headers
.endif	# OPENCL_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencl-headers
