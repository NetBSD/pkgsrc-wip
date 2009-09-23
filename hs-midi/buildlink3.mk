# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 07:11:21 phonohawk Exp $

BUILDLINK_TREE+=	hs-midi

.if !defined(HS_MIDI_BUILDLINK3_MK)
HS_MIDI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-midi+=	hs-midi>=0.1.4
BUILDLINK_PKGSRCDIR.hs-midi?=	../../wip/hs-midi

.include "../../wip/hs-binary/buildlink3.mk"
.include "../../wip/hs-event-list/buildlink3.mk"
.include "../../wip/hs-explicit-exception/buildlink3.mk"
.include "../../wip/hs-monoid-transformer/buildlink3.mk"
.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_MIDI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-midi
