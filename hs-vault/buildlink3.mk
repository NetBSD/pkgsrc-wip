# $NetBSD: buildlink3.mk,v 1.3 2013/12/10 21:51:16 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vault

.if !defined(HS_VAULT_BUILDLINK3_MK)
HS_VAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vault+=	hs-vault>=0.3
BUILDLINK_PKGSRCDIR.hs-vault?=	../../wip/hs-vault

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.endif	# HS_VAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vault
