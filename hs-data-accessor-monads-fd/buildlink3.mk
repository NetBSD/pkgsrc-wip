# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-accessor-monads-fd

.if !defined(HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK)
HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-accessor-monads-fd+=	hs-data-accessor-monads-fd>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-data-accessor-monads-fd+=	hs-data-accessor-monads-fd>=0.2.0.3
BUILDLINK_PKGSRCDIR.hs-data-accessor-monads-fd?=	../../wip/hs-data-accessor-monads-fd

.include "../../wip/hs-data-accessor/buildlink3.mk"
.include "../../wip/hs-monads-fd/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_DATA_ACCESSOR_MONADS_FD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-accessor-monads-fd
