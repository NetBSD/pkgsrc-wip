# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/01 04:41:27 phonohawk Exp $

BUILDLINK_TREE+=	hs-HSH

.if !defined(HS_HSH_BUILDLINK3_MK)
HS_HSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HSH+=	hs-HSH>=2.0.3
BUILDLINK_PKGSRCDIR.hs-HSH?=	../../wip/hs-HSH

.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../wip/hs-hslogger/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"
.endif	# HS_HSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HSH
