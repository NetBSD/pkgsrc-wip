# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/18 04:51:37 mpasternak Exp $

.if !defined(XBASE_BUILDLINK2_MK)
XBASE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xbase
BUILDLINK_DEPENDS.xbase?=	xbase>=2.0.0
BUILDLINK_PKGSRCDIR.xbase?=	../../wip/xbase

EVAL_PREFIX+=			BUILDLINK_PREFIX.xbase=xbase
BUILDLINK_PREFIX.xbase_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xbase=	include/xbase/*
BUILDLINK_FILES.xbase+=	lib/libxbase* 
BUILDLINK_FILES.xbase+=	bin/xbase-config

BUILDLINK_TARGETS+=	xbase-buildlink

xbase-buildlink: _BUILDLINK_USE

.endif	# XBASE_BUILDLINK2_MK
