# $NetBSD: buildlink2.mk,v 1.2 2003/11/28 16:51:29 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use libxml++.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBXMLXX_BUILDLINK2_MK)
LIBXMLXX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libxmlxx
BUILDLINK_DEPENDS.libxmlxx?=		libxml++>=0.27.0
BUILDLINK_PKGSRCDIR.libxmlxx?=		../../new/libxml++

EVAL_PREFIX+=	BUILDLINK_PREFIX.libxmlxx=libxmlxx
BUILDLINK_PREFIX.libxmlxx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libxmlxx+=	include/libxml++-1.0/libxml++/*.h
BUILDLINK_FILES.libxmlxx+=	include/libxml++-1.0/libxml++/exceptions/*.h
BUILDLINK_FILES.libxmlxx+=	include/libxml++-1.0/libxml++/io/*.h
BUILDLINK_FILES.libxmlxx+=	include/libxml++-1.0/libxml++/nodes/*.h
BUILDLINK_FILES.libxmlxx+=	include/libxml++-1.0/libxml++/parsers/*.h
BUILDLINK_FILES.libxmlxx+=	lib/libio.*
BUILDLINK_FILES.libxmlxx+=	lib/libxml++-0.1.*

.include "../../textproc/libxml2/buildlink2.mk"

BUILDLINK_TARGETS+=	libxmlxx-buildlink

libxmlxx-buildlink: _BUILDLINK_USE

.endif	# LIBXMLXX_BUILDLINK2_MK
