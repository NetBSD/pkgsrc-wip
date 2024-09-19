# $NetBSD$

BUILDLINK_TREE+=	seafile-client
BUILDLINK_TREE+=	libseafile

.if !defined(SEAFILE_CLIENT_BUILDLINK3_MK)
SEAFILE_CLIENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.seafile-client+=	seafile-client>=6.0.0
BUILDLINK_PKGSRCDIR.seafile-client?=	../../wip/seafile-client
.endif	# SEAFILE_CLIENT_BUILDLINK3_MK


.if !defined(LIBSEAFILE_BUILDLINK3_MK)
LIBSEAFILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libseafile+=	seafile-client>=6.0.0
BUILDLINK_PKGSRCDIR.libseafile?=	../../wip/seafile-client
.endif	# LIBSEAFILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libseafile
BUILDLINK_TREE+=	-seafile-client
