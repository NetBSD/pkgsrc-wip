# $NetBSD: buildlink3.mk,v 1.2 2013/05/16 10:56:24 othyro Exp $

BUILDLINK_TREE+=	libtifiles2

.if !defined(LIBTIFILES2_BUILDLINK3_MK)
LIBTIFILES2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtifiles2+=	libtifiles2>=1.1.5
BUILDLINK_PKGSRCDIR.libtifiles2?=	../../wip/libtifiles2

pkgbase := libtifiles2
.include "../../mk/pkg-build-options.mk"


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/libticonv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# LIBTIFILES2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtifiles2
