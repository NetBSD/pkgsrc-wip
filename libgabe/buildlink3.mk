# $NetBSD$

BUILDLINK_TREE+=	libgabe

.if !defined(LIBGABE_BUILDLINK3_MK)
LIBGABE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgabe+=	libgabe>=0.0
BUILDLINK_PKGSRCDIR.libgabe?=	../../wip/libgabe

pkgbase:= libgabe
.include "../../mk/pkg-build-options.mk"

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../wip/libpbc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBGABE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgabe
