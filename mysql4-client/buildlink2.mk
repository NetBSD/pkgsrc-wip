# $NetBSD: buildlink2.mk,v 1.5 2003/09/17 20:52:58 adrian_p Exp $

.if !defined(MYSQL_CLIENT_BUILDLINK2_MK)
MYSQL_CLIENT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mysql4-client
BUILDLINK_DEPENDS.mysql4-client?=	mysql4-client>=4.0.15
BUILDLINK_PKGSRCDIR.mysql4-client?=	../../wip/mysql4-client

EVAL_PREFIX+=	BUILDLINK_PREFIX.mysql4-client=mysql4-client
BUILDLINK_PREFIX.mysql4-client_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mysql4-client=	include/mysql/*.h
BUILDLINK_FILES.mysql4-client+=	lib/mysql/libmysqlclient.*

FIX_RPATH+=	BUILDLINK_LDFLAGS.mysql4-client
BUILDLINK_LDFLAGS.mysql4-client= \
	-L${BUILDLINK_PREFIX.mysql4-client}/lib/mysql			\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.mysql4-client}/lib/mysql

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

BUILDLINK_TARGETS+=	mysql4-client-buildlink

mysql4-client-buildlink: _BUILDLINK_USE

.endif	# MYSQL_CLIENT_BUILDLINK2_MK
