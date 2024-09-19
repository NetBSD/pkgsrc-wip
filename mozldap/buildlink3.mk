# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/08/21 03:45:36 udontknow Exp $

BUILDLINK_TREE+=	mozldap

.if !defined(MOZLDAP_BUILDLINK3_MK)
MOZLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mozldap+=	mozldap>=6.0.6
BUILDLINK_PKGSRCDIR.mozldap?=	../../wip/mozldap

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../wip/svrcore/buildlink3.mk"
.endif	# MOZLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mozldap
