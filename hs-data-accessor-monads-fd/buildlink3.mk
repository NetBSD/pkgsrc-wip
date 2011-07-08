# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/08 08:38:18 phonohawk Exp $

BUILDLINK_TREE+=	hs-data-accessor-monads-fd

.if !defined(HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK)
HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor-monads-fd+=	hs-data-accessor-monads-fd>=0.2
BUILDLINK_PKGSRCDIR.hs-data-accessor-monads-fd?=	../../wip/hs-data-accessor-monads-fd

.include "../../wip/hs-data-accessor/buildlink3.mk"
.include "../../wip/hs-monads-fd/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor-monads-fd
