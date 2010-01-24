# $NetBSD: buildlink3.mk,v 1.3 2010/01/24 03:36:56 phonohawk Exp $

BUILDLINK_TREE+=	hs-HDBC-sqlite3

.if !defined(HS_HDBC_SQLITE3_BUILDLINK3_MK)
HS_HDBC_SQLITE3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HDBC-sqlite3+=	hs-HDBC-sqlite3>=2.1.0.2
BUILDLINK_PKGSRCDIR.hs-HDBC-sqlite3?=	../../wip/hs-HDBC-sqlite3

.include "../../wip/hs-convertible/buildlink3.mk"
.include "../../wip/hs-HDBC/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-utf8-string/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.endif	# HS_HDBC_SQLITE3_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HDBC-sqlite3
