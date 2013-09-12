# $NetBSD: buildlink3.mk,v 1.2 2013/09/12 20:11:38 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vault

.if !defined(HS_VAULT_BUILDLINK3_MK)
HS_VAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vault+=	hs-vault>=0.3
BUILDLINK_PKGSRCDIR.hs-vault?=	../../wip/hs-vault
.endif	# HS_VAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vault
