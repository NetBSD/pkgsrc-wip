# $NetBSD$

BUILDLINK_TREE+=	seafile-daemon
BUILDLINK_TREE+=	libseafile

.if !defined(SEAFILE_DAEMON_BUILDLINK3_MK)
SEAFILE_DAEMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seafile-daemon+=	seafile-daemon>=6.0.0
BUILDLINK_PKGSRCDIR.seafile-daemon?=	../../wip/seafile-daemon
.endif	# SEAFILE_DAEMON_BUILDLINK3_MK


.if !defined(LIBSEAFILE_BUILDLINK3_MK)
LIBSEAFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libseafile+=	seafile-daemon>=6.0.0
BUILDLINK_PKGSRCDIR.libseafile?=	../../wip/seafile-daemon
.endif	# LIBSEAFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libseafile
BUILDLINK_TREE+=	-seafile-daemon
