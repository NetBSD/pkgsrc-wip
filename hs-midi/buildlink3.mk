# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:10:26 szptvlfn Exp $

BUILDLINK_TREE+=	hs-midi

.if !defined(HS_MIDI_BUILDLINK3_MK)
HS_MIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-midi+=	hs-midi>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-midi+=	hs-midi>=0.1.7.1
BUILDLINK_PKGSRCDIR.hs-midi?=	../../wip/hs-midi

.include "../../wip/hs-event-list/buildlink3.mk"
.include "../../wip/hs-explicit-exception/buildlink3.mk"
.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-midi
