# $NetBSD$

BUILDLINK_TREE+=	libinput-bsd-headers

.if !defined(LIBINPUT_BSD_HEADERS_BUILDLINK3_MK)
LIBINPUT_BSD_HEADERS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.libinput-bsd-headers?=	build

BUILDLINK_API_DEPENDS.libinput-bsd-headers+=	libinput-bsd-headers>=1.26.2
BUILDLINK_PKGSRCDIR.libinput-bsd-headers?=	../../wip/libinput-bsd-headers
.endif	# LIBINPUT_BSD_HEADERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libinput-bsd-headers
