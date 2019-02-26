# $NetBSD$

BUILDLINK_TREE+=	zbar

.if !defined(ZBAR_BUILDLINK3_MK)
ZBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zbar+=	zbar>=0.10
BUILDLINK_PKGSRCDIR.zbar?=	../../wip/zbar

pkgbase:=	zbar
.include "../../mk/pkg-build-options.mk"

.endif # ZBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-zbar
