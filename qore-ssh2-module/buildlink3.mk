# $NetBSD: buildlink3.mk,v 1.1 2014/01/24 20:02:37 nros Exp $

BUILDLINK_TREE+=	qore-ssh2-module

.if !defined(QORE_SSH2_MODULE_BUILDLINK3_MK)
QORE_SSH2_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-ssh2-module+=	qore-ssh2-module>=0.9.9
BUILDLINK_PKGSRCDIR.qore-ssh2-module?=	../../wip/qore-ssh2-module

.include "../../wip/qore/buildlink3.mk"
.endif	# QORE_SSH2_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-ssh2-module
