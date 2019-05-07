# $NetBSD$

BUILDLINK_TREE+=	pbc

.if !defined(PBC_BUILDLINK3_MK)
PBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pbc+=	pbc>=0.5.14
BUILDLINK_PKGSRCDIR.pbc?=	../../wip/libpbc

pkgbase:= pbc
.include "../../mk/pkg-build-options.mk"

.include "../../devel/gmp/buildlink3.mk"
.endif # PBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-pbc
