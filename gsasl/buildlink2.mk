# $NetBSD: buildlink2.mk,v 1.2 2003/10/30 10:07:43 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gsasl.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GSASL_BUILDLINK2_MK)
GSASL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gsasl
BUILDLINK_DEPENDS.gsasl?=		gsasl>=0.0.8
BUILDLINK_PKGSRCDIR.gsasl?=		../../wip/gsasl

EVAL_PREFIX+=	BUILDLINK_PREFIX.gsasl=gsasl
BUILDLINK_PREFIX.gsasl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gsasl+=	include/gsasl.h
BUILDLINK_FILES.gsasl+=	lib/libgsasl.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"
.include "../../wip/gss/buildlink2.mk"
.include "../../wip/libidn/buildlink2.mk"
.include "../../wip/libntlm/buildlink2.mk"

BUILDLINK_TARGETS+=	gsasl-buildlink

gsasl-buildlink: _BUILDLINK_USE

.endif	# GSASL_BUILDLINK2_MK
