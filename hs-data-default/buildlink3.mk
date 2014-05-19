# $NetBSD: buildlink3.mk,v 1.6 2014/05/19 21:28:47 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.5.3
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../wip/hs-data-default

.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-data-default-instances-base/buildlink3.mk"
.include "../../devel/hs-data-default-instances-containers/buildlink3.mk"
.include "../../devel/hs-data-default-instances-dlist/buildlink3.mk"
.include "../../devel/hs-data-default-instances-old-locale/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
