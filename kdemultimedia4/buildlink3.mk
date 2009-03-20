# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	kdemultimedia4

.if !defined(KDEMULTIMEDIA4_BUILDLINK3_MK)
KDEMULTIMEDIA4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdemultimedia4+=	kdemultimedia4>=4.1.0
BUILDLINK_PKGSRCDIR.kdemultimedia4?=	../../wip/kdemultimedia4

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
.endif # KDEMULTIMEDIA4_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdemultimedia4
