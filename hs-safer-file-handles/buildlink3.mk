# $NetBSD: buildlink3.mk,v 1.2 2010/12/30 08:52:32 phonohawk Exp $

BUILDLINK_TREE+=	hs-safer-file-handles

.if !defined(HS_SAFER_FILE_HANDLES_BUILDLINK3_MK)
HS_SAFER_FILE_HANDLES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-safer-file-handles+=	hs-safer-file-handles>=0.9
BUILDLINK_PKGSRCDIR.hs-safer-file-handles?=	../../wip/hs-safer-file-handles

.include "../../wip/hs-base-unicode-symbols/buildlink3.mk"
.include "../../wip/hs-explicit-iomodes/buildlink3.mk"
.include "../../wip/hs-monad-peel/buildlink3.mk"
.include "../../wip/hs-pathtype/buildlink3.mk"
.include "../../wip/hs-regional-pointers/buildlink3.mk"
.include "../../wip/hs-regions/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.endif	# HS_SAFER_FILE_HANDLES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-safer-file-handles
