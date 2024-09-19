# $NetBSD: buildlink3.mk,v 1.1 2015/06/08 23:28:19 krytarowski Exp $

BUILDLINK_TREE+=	accountsservice

.if !defined(ACCOUNTSSERVICE_BUILDLINK3_MK)
ACCOUNTSSERVICE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.accountsservice+=	accountsservice>=0.6.40
BUILDLINK_ABI_DEPENDS.accountsservice?=	accountsservice>=0.6.55nb1
BUILDLINK_PKGSRCDIR.accountsservice?=	../../wip/accountsservice

# XXX: option?
.include "../../devel/gobject-introspection/buildlink3.mk"

.include "../../security/polkit/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# ACCOUNTSSERVICE_BUILDLINK3_MK

BUILDLINK_TREE+=	-accountsservice
