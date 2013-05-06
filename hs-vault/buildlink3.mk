# $NetBSD: buildlink3.mk,v 1.1 2013/05/06 21:29:57 szptvlfn Exp $

BUILDLINK_TREE+=	hs-vault

.if !defined(HS_VAULT_BUILDLINK3_MK)
HS_VAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-vault+=	hs-vault>=0.2.0
BUILDLINK_PKGSRCDIR.hs-vault?=	../../wip/hs-vault
.endif	# HS_VAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-vault
