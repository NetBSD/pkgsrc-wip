# $NetBSD: buildlink3.mk,v 1.1 2008/08/18 06:41:57 thomasklausner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
KDEMULTIMEDIA4_BUILDLINK3_MK:=	${KDEMULTIMEDIA4_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdemultimedia4
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdemultimedia4}
BUILDLINK_PACKAGES+=	kdemultimedia4
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdemultimedia4

.if ${KDEMULTIMEDIA4_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdemultimedia4+=	kdemultimedia4>=4.1.0
BUILDLINK_PKGSRCDIR.kdemultimedia4?=	../../wip/kdemultimedia4
.endif	# KDEMULTIMEDIA4_BUILDLINK3_MK

# XXX: didn't seem necessary for amarok, so leave them disabled.
#.include "../../audio/cdparanoia/buildlink3.mk"
#.include "../../audio/flac/buildlink3.mk"
#.include "../../audio/libtunepimp/buildlink3.mk"
#.include "../../audio/musicbrainz/buildlink3.mk"
#.include "../../audio/taglib/buildlink3.mk"
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../multimedia/libtheora/buildlink3.mk"
#.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdebase-runtime4/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
