# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/22 12:55:20 obache Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
QDBM_BUILDLINK3_MK:=	${QDBM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qdbm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqdbm}
BUILDLINK_PACKAGES+=	qdbm

.if !empty(QDBM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.qdbm+=	qdbm>=1.8.33
BUILDLINK_PKGSRCDIR.qdbm?=	../../wip/qdbm
.endif	# QDBM_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
