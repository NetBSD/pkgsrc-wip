# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/29 14:41:07 mpasternak Exp $
#
# This Makefile fragment is included by packages that use pango-devel.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(PANGO_DEVEL_BUILDLINK2_MK)
PANGO_DEVEL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			pango-devel
BUILDLINK_DEPENDS.pango-devel?=		pango-devel>=1.3.1
BUILDLINK_PKGSRCDIR.pango-devel?=		../../wip/pango-devel

EVAL_PREFIX+=	BUILDLINK_PREFIX.pango-devel=pango-devel
BUILDLINK_PREFIX.pango-devel_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-attributes.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-break.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-context.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-coverage.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-engine.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-enum-types.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-font.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-fontmap.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-fontset.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-glyph-item.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-glyph.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-item.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-layout.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-modules.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-ot.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-script.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-tabs.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-types.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango-utils.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pango.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pangofc-font.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pangofc-fontmap.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pangoft2.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pangox.h
BUILDLINK_FILES.pango-devel+=	include/pango-1.0/pango/pangoxft.h
BUILDLINK_FILES.pango-devel+=	lib/libpango-1.0.*
BUILDLINK_FILES.pango-devel+=	lib/libpangoft2-1.0.*
BUILDLINK_FILES.pango-devel+=	lib/libpangox-1.0.*
BUILDLINK_FILES.pango-devel+=	lib/libpangoxft-1.0.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-arabic-fc.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-basic-fc.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-basic-x.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-hangul-fc.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-hebrew-fc.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-indic-fc.*
BUILDLINK_FILES.pango-devel+=	lib/pango/1.4.0/modules/pango-thai-fc.*

.include "../../wip/glib2-devel/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"

BUILDLINK_TARGETS+=	pango-devel-buildlink

pango-devel-buildlink: _BUILDLINK_USE

.endif	# PANGO_DEVEL_BUILDLINK2_MK
