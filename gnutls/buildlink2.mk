# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/13 02:33:09 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnutls.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GNUTLS_BUILDLINK2_MK)
GNUTLS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gnutls
BUILDLINK_DEPENDS.gnutls?=		gnutls>=0.8.7
BUILDLINK_PKGSRCDIR.gnutls?=		../../wip/gnutls

EVAL_PREFIX+=	BUILDLINK_PREFIX.gnutls=gnutls
BUILDLINK_PREFIX.gnutls_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gnutls+=	include/gnutls/*.h
BUILDLINK_FILES.gnutls+=	lib/libgnutls-extra.*
BUILDLINK_FILES.gnutls+=	lib/libgnutls.*

.include "../../wip/libopencdk/buildlink2.mk"	
.include "../../wip/libtasn1/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

BUILDLINK_TARGETS+=	gnutls-buildlink

gnutls-buildlink: _BUILDLINK_USE

.endif	# GNUTLS_BUILDLINK2_MK
