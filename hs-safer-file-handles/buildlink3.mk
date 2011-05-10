# $NetBSD: buildlink3.mk,v 1.3 2011/05/10 23:38:03 phonohawk Exp $

BUILDLINK_TREE+=	hs-safer-file-handles

.if !defined(HS_SAFER_FILE_HANDLES_BUILDLINK3_MK)
HS_SAFER_FILE_HANDLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safer-file-handles+=	hs-safer-file-handles>=0.10
BUILDLINK_PKGSRCDIR.hs-safer-file-handles?=	../../wip/hs-safer-file-handles

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-explicit-iomodes/buildlink3.mk"
.include "../../wip/hs-monad-control/buildlink3.mk"
.include "../../wip/hs-pathtype/buildlink3.mk"
.include "../../wip/hs-regional-pointers/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_SAFER_FILE_HANDLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safer-file-handles
