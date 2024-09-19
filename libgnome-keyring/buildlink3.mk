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
# XXX	BUILDLINK_DEPMETHOD.libgnome-keyring?=	build

BUILDLINK_TREE+=	libgnome-keyring

.if !defined(LIBGNOME_KEYRING_BUILDLINK3_MK)
LIBGNOME_KEYRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-keyring+=	libgnome-keyring>=3.12.0
BUILDLINK_PKGSRCDIR.libgnome-keyring?=	../../wip/libgnome-keyring

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.endif	# LIBGNOME_KEYRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-keyring
