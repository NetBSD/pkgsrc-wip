# $NetBSD: buildlink2.mk,v 1.1 2003/09/30 15:39:59 hfath Exp $

.if !defined(CNEWS_BUILDLINK2_MK)
CNEWS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		cnews
BUILDLINK_DEPENDS.cnews?=	c-news-*
BUILDLINK_PKGSRCDIR.cnews?=	../../news/cnews

EVAL_PREFIX+=			BUILDLINK_PREFIX.cnews=cnews
BUILDLINK_PREFIX.cnews_DEFAULT= ${LOCALBASE}
BUILDLINK_FILES.cnews=		include/dbz.h
BUILDLINK_FILES.cnews+=		lib/libcnews.*

BUILDLINK_TARGETS+=		cnews-buildlink

cnews-buildlink: _BUILDLINK_USE

.endif	# CNEWS_BUILDLINK2_MK
