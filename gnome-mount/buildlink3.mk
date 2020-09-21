# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.17.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gnome-mount?=	build

BUILDLINK_TREE+=	gnome-mount

.if !defined(GNOME_MOUNT_BUILDLINK3_MK)
GNOME_MOUNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-mount+=	gnome-mount>=0.8nb37
BUILDLINK_PKGSRCDIR.gnome-mount?=	../../wip/gnome-mount

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX

DEPENDS+=	gvfs>0:../../sysutils/gvfs

.include "../../devel/libglade/buildlink3.mk"
.include "../../wip/libgnome-keyring/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/hal/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.endif	# GNOME_MOUNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-mount
