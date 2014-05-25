# $NetBSD: buildlink3.mk,v 1.4 2014/05/25 21:59:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vault

.if !defined(HS_VAULT_BUILDLINK3_MK)
HS_VAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vault+=	hs-vault>=0.3
BUILDLINK_PKGSRCDIR.hs-vault?=	../../wip/hs-vault

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_VAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vault
