# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/23 11:52:42 phonohawk Exp $

BUILDLINK_TREE+=	hs-numeric-prelude

.if !defined(HS_NUMERIC_PRELUDE_BUILDLINK3_MK)
HS_NUMERIC_PRELUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-numeric-prelude+=	hs-numeric-prelude>=0.1.2
BUILDLINK_PKGSRCDIR.hs-numeric-prelude?=	../../wip/hs-numeric-prelude

.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-QuickCheck1/buildlink3.mk"
.include "../../wip/hs-storable-record/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_NUMERIC_PRELUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-numeric-prelude
