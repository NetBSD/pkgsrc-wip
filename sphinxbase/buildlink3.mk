# $NetBSD: buildlink3.mk,v 1.1 2013/09/24 10:40:19 fhajny Exp $

BUILDLINK_TREE+=	sphinxbase

.if !defined(SPHINXBASE_BUILDLINK3_MK)
SPHINXBASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sphinxbase+=	sphinxbase>=0.8
BUILDLINK_ABI_DEPENDS.sphinxbase+=	sphinxbase>=0.8
BUILDLINK_PKGSRCDIR.sphinxbase?=	../../wip/sphinxbase
BUILDLINK_INCDIRS.sphinxbase+=		include/sphinxbase

pkgbase:= sphinxbase
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.sphinxbase:Msamplerate)
.  include "../../audio/libsamplerate/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.sphinxbase:Msndfile)
.  include "../../audio/libsndfile/buildlink3.mk"
.endif
.endif

BUILDLINK_TREE+=	-sphinxbase
