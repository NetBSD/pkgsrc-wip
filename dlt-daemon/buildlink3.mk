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
# XXX	BUILDLINK_DEPMETHOD.dlt-daemon?=	build

BUILDLINK_TREE+=	dlt-daemon

.if !defined(DLT_DAEMON_BUILDLINK3_MK)
DLT_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dlt-daemon+=	dlt-daemon>=2.16.0
BUILDLINK_PKGSRCDIR.dlt-daemon?=	../../wip/dlt-daemon

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../sysutils/dbus/buildlink3.mk"
.endif	# DLT_DAEMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-dlt-daemon
