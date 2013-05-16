# $NetBSD: buildlink3.mk,v 1.2 2013/05/16 11:10:49 othyro Exp $

BUILDLINK_TREE+=	libticalcs2

.if !defined(LIBTICALCS2_BUILDLINK3_MK)
LIBTICALCS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libticalcs2+=	libticalcs2>=1.1.7
BUILDLINK_PKGSRCDIR.libticalcs2?=	../../wip/libticalcs2

pkgbase := libticalcs2
.include "../../mk/pkg-build-options.mk"


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/libtifiles2/buildlink3.mk"
.include "../../wip/libticonv/buildlink3.mk"
.include "../../wip/libticables2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBTICALCS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libticalcs2
