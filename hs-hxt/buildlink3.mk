# $NetBSD: buildlink3.mk,v 1.11 2014/08/29 14:10:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hxt

.if !defined(HS_HXT_BUILDLINK3_MK)
HS_HXT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt+=	hs-hxt>=9.3.1
BUILDLINK_ABI_DEPENDS.hs-hxt+=	hs-hxt>=9.3.1.1
BUILDLINK_PKGSRCDIR.hs-hxt?=	../../wip/hs-hxt

.include "../../wip/hs-hxt-charproperties/buildlink3.mk"
.include "../../textproc/hs-hxt-regex-xmlschema/buildlink3.mk"
.include "../../textproc/hs-hxt-unicode/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_HXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt
