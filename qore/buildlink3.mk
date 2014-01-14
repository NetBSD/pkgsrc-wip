# $NetBSD: buildlink3.mk,v 1.1 2014/01/14 19:27:10 nros Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=0.8.8
BUILDLINK_PKGSRCDIR.qore?=	../../wip/qore


.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
