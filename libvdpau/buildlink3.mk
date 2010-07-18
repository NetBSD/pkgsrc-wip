# $NetBSD: buildlink3.mk,v 1.2 2010/07/18 09:14:22 cheusov Exp $
.include "../../mk/bsd.prefs.mk"

# VDPAU is available only for Linux, FreeBSD and Solaris.
# The following condition is to NOT list these platforms in several places, e.g.
# in mplayer, xine, xbmc etc.
#
# For linking use LDFLAGS.vdpau variable!

.if ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "SunOS"

BUILDLINK_TREE+=	libvdpau

.if !defined(LIBVDPAU_BUILDLINK3_MK)
LIBVDPAU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvdpau+=	libvdpau>=0.3
BUILDLINK_PKGSRCDIR.libvdpau?=	../../wip/libvdpau

# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/libX11/buildlink3.mk"
.endif	# LIBVDPAU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvdpau

LDFLAGS.vdpau=		-lvdpau

.endif # Linux, FreeBSD, SunOS...
