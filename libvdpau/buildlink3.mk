# $NetBSD: buildlink3.mk,v 1.5 2010/07/23 23:04:15 cheusov Exp $

#
# For linking use LDFLAGS.vdpau variable
#

# Check whether VDPAU is available on this platform
.include "../../wip/libvdpau/available.mk"
.if ${VDPAU_AVAILABLE} == "yes"

BUILDLINK_TREE+=	libvdpau

.  if !defined(LIBVDPAU_BUILDLINK3_MK)
LIBVDPAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvdpau+=	libvdpau>=0.3
BUILDLINK_PKGSRCDIR.libvdpau?=	../../wip/libvdpau

.include "../../x11/libX11/buildlink3.mk"
.  endif	# LIBVDPAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvdpau

LDFLAGS.vdpau=		-lvdpau

.endif # Linux, FreeBSD, SunOS...
