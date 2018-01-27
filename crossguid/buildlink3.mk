# $NetBSD$
BUILDLINK_TREE+=	crossguid

.if !defined(CROSSGUID_BUILDLINK3_MK)
CROSSGUID_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crossguid+=	crossguid>=0.0_pre20160908
BUILDLINK_PKGSRCDIR.crossguid?=		../../devel/crossguid

.include "../../devel/libuuid/buildlink3.mk"
.endif	# CROSSGUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-crossguid
