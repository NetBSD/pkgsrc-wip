# $NetBSD$

BUILDLINK_TREE+=	aircrack-ng

.if !defined(AIRCRACK_NG_BUILDLINK3_MK)
AIRCRACK_NG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aircrack-ng+=	aircrack-ng>=1.7
BUILDLINK_PKGSRCDIR.aircrack-ng?=	../../wip/aircrack-ng

.include "../../security/openssl/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# AIRCRACK_NG_BUILDLINK3_MK

BUILDLINK_TREE+=	-aircrack-ng
