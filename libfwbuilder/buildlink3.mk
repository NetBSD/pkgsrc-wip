# $NetBSD: buildlink3.mk,v 1.1 2004/04/27 00:46:29 blef Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBFWBUILDER_BUILDLINK3_MK:=	${LIBFWBUILDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libfwbuilder
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibfwbuilder}
BUILDLINK_PACKAGES+=	libfwbuilder

.if !empty(LIBFWBUILDER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libfwbuilder+=	libfwbuilder>=1.0.2
BUILDLINK_PKGSRCDIR.libfwbuilder?=	../../wip/libfwbuilder
.endif	# LIBFWBUILDER_BUILDLINK3_MK

.include "../../net/bind9/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.if defined(FWBUILDER_USE_BIND) && !empty(FWBUILDER_USE_BIND:M[yY][eE][sS])
.include "../../net/bind9/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
