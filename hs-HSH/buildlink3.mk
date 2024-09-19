# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HSH

.if !defined(HS_HSH_BUILDLINK3_MK)
HS_HSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HSH+=	hs-HSH>=2.0.3
BUILDLINK_ABI_DEPENDS.hs-HSH+=	hs-HSH>=2.0.3
BUILDLINK_PKGSRCDIR.hs-HSH?=	../../wip/hs-HSH

.include "../../wip/hs-MissingH/buildlink3.mk"
.include "../../sysutils/hs-hslogger/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../textproc/hs-regex-posix/buildlink3.mk"
.endif	# HS_HSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HSH
