# $NetBSD: buildlink3.mk,v 1.2 2004/03/06 04:59:03 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POSTGRESQL74_LIB_BUILDLINK3_MK:=	${POSTGRESQL74_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql74-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql74-lib}
BUILDLINK_PACKAGES+=	postgresql74-lib

.if !empty(POSTGRESQL74_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql74-lib+=	postgresql74-lib>=7.4.1
BUILDLINK_PKGSRCDIR.postgresql74-lib?=	../../wip/postgresql74-lib

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# POSTGRESQL74_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
