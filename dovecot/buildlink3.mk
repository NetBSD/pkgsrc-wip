# $NetBSD: buildlink3.mk,v 1.2 2007/10/01 04:22:21 ghen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=		${OPENLDAP_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			dovecot
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Ndovecot}
BUILDLINK_PACKAGES+=			dovecot
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dovecot

.if !empty(OPENLDAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.1beta2
BUILDLINK_PKGSRCDIR.dovecot?=		../../wip/dovecot
.endif

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
