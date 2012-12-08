# $NetBSD: buildlink3.mk,v 1.1 2012/12/08 22:41:37 othyro Exp $

BUILDLINK_TREE+=	libcerror

.if !defined(LIBCERROR_BUILDLINK3_MK)
LIBCERROR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcerror+=	libcerror>=20120507
BUILDLINK_PKGSRCDIR.libcerror?=	../../wip/libcerror

pkgbase := libcerror
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.libcerror:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.endif	# LIBCERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcerror
