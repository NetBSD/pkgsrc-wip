# $NetBSD: buildlink2.mk,v 1.2 2003/11/18 05:16:06 mpasternak Exp $

.if !defined(XBSQL_BUILDLINK2_MK)
XBSQL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		xbsql
BUILDLINK_DEPENDS.xbsql?=	xbsql>=0.11
BUILDLINK_PKGSRCDIR.xbsql?=	../../wip/xbsql

EVAL_PREFIX+=			BUILDLINK_PREFIX.xbsql=xbsql
BUILDLINK_PREFIX.xbsql_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.xbsql=	include/xbsql.h
BUILDLINK_FILES.xbsql+=	lib/libxbsql* 
BUILDLINK_FILES.xbsql+=	bin/xql

.include "../../wip/xbase/buildlink2.mk"

BUILDLINK_TARGETS+=	xbsql-buildlink

xbsql-buildlink: _BUILDLINK_USE

.endif	# XBSQL_BUILDLINK2_MK
