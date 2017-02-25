# $NetBSD$

BUILDLINK_TREE+=	seafile-server
BUILDLINK_TREE+=	libseafile

.if !defined(SEAFILE_SERVER_BUILDLINK3_MK)
SEAFILE_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seafile-server+=	seafile-server>=6.0.0
BUILDLINK_PKGSRCDIR.seafile-server?=	../../wip/seafile-server
.endif	# SEAFILE_SERVER_BUILDLINK3_MK


.if !defined(LIBSEAFILE_BUILDLINK3_MK)
LIBSEAFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libseafile+=	seafile-server>=6.0.0
BUILDLINK_PKGSRCDIR.libseafile?=	../../wip/seafile-server
.endif	# LIBSEAFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libseafile
BUILDLINK_TREE+=	-seafile-server
