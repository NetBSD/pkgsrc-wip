# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/01/20 00:25:56 xtraeme Exp $
#
# This Makefile fragment is included by packages that use postgresql74-lib.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POSTGRESQL74_LIB_BUILDLINK3_MK:=	${POSTGRESQL74_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql74-lib
.endif

.if !empty(POSTGRESQL74_LIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			postgresql74-lib
BUILDLINK_DEPENDS.postgresql74-lib?=		postgresql74-lib>=7.4.1
BUILDLINK_PKGSRCDIR.postgresql74-lib?=		../../wip/postgresql74-lib

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif # POSTGRESQL74_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
