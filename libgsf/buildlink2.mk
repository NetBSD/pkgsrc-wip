# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/12 21:48:02 jeremy-c-reed Exp $

.if !defined(LIBGSF_BUILDLINK2_MK)
LIBGSF_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgsf
BUILDLINK_DEPENDS.libgsf?=	libgsf>=1.8.0
BUILDLINK_PKGSRCDIR.libgsf?=	../../devel/libgsf

EVAL_PREFIX+=			BUILDLINK_PREFIX.libgsf=libgsf
BUILDLINK_PREFIX.libgsf_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.libgsf=		include/libgsf-1/gsf/*.h
BUILDLINK_FILES.libgsf+=	lib/libgsf-1*

.include "../../devel/glib2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=		libgsf-buildlink

libgsf-buildlink: _BUILDLINK_USE

.endif	# LIBGSF_BUILDLINK2_MK
