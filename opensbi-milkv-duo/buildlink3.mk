# $NetBSD$

BUILDLINK_TREE+=	opensbi-milkv-duo

.if !defined(OPENSBI_MILKV_DUO_BUILDLINK3_MK)
OPENSBI_MILKV_DUO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.opensbi-milkv-duo?=		build
BUILDLINK_API_DEPENDS.opensbi-milkv-duo+=	opensbi-milkv-duo>=1.4
BUILDLINK_PKGSRCDIR.opensbi-milkv-duo?=		../../wip/opensbi-milkv-duo
.endif	# OPENSBI_MILKV_DUO_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensbi-milkv-duo
