# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/20 05:14:46 obache Exp $
#

BUILDLINK_TREE+=	libdlna

.if !defined(LIBDLNA_BUILDLINK3_MK)
LIBDLNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdlna+=	libdlna>=0.2.3
BUILDLINK_PKGSRCDIR.libdlna?=	../../wip/libdlna

#.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif	# LIBDLNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdlna
