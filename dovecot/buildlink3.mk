# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:40 jsonn Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.2alpha1
BUILDLINK_PKGSRCDIR.dovecot?=		../../wip/dovecot
.endif

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
