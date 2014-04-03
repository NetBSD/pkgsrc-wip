# $NetBSD: buildlink3.mk,v 1.2 2014/04/03 15:36:49 nros Exp $
#

BUILDLINK_TREE+=	qore

.if !defined(QORE_BUILDLINK3_MK)
QORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore+=	qore>=0.8.8
BUILDLINK_PKGSRCDIR.qore?=	../../wip/qore

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# QORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore
