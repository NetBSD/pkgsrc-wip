# $NetBSD: buildlink3.mk,v 1.1 2004/04/28 00:13:17 blef Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBETPAN_BUILDLINK3_MK:=	${LIBETPAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libetpan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibetpan}
BUILDLINK_PACKAGES+=	libetpan

.if !empty(LIBETPAN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libetpan+=	libetpan>=0.32
BUILDLINK_PKGSRCDIR.libetpan?=	../../wip/libetpan
.endif	# LIBETPAN_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
