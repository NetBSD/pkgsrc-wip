# $NetBSD: buildlink3.mk,v 1.2 2007/03/27 23:51:53 thomasklausner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
FFMPEG_SNAPSHOT_BUILDLINK3_MK:=	${FFMPEG_SNAPSHOT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ffmpeg-snapshot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nffmpeg-snapshot}
BUILDLINK_PACKAGES+=	ffmpeg-snapshot
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ffmpeg-snapshot

.if ${FFMPEG_SNAPSHOT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ffmpeg-snapshot+=	ffmpeg-snapshot>=20061213
BUILDLINK_PKGSRCDIR.ffmpeg-snapshot?=	../../wip/ffmpeg-snapshot
.endif	# FFMPEG_SNAPSHOT_BUILDLINK3_MK

.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
