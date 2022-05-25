# $NetBSD$

# devel/pkgconf has no bl3 file.
# This package uses the pkgconf library, therefore DEPENDS is not sufficient.

BUILDLINK_TREE+=	pkgconf

.if !defined(PKGCONF_BUILDLINK3_MK)
PKGCONF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pkgconf+=		pkgconf>=1.8.0
BUILDLINK_PKGSRCDIR.pkgconf?=		../../devel/pkgconf
.endif	# PKGCONF_BUILDLINK3_MK

BUILDLINK_TREE+=	-pkgconf
