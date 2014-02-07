# $NetBSD: buildlink3.mk,v 1.1 2014/02/07 14:17:07 nros Exp $
#

BUILDLINK_TREE+=	qore-mysql-module

.if !defined(QORE_MYSQL_MODULE_BUILDLINK3_MK)
QORE_MYSQL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-mysql-module+=	qore-mysql-module>=2.0.1
BUILDLINK_PKGSRCDIR.qore-mysql-module?=	../../wip/qore-mysql-module

.include "../../wip/qore/buildlink3.mk"
.endif	# QORE_MYSQL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-mysql-module
