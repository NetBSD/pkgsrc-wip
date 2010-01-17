# $NetBSD: buildlink3.mk,v 1.2 2010/01/17 12:03:29 thomasklausner Exp $
#

BUILDLINK_TREE+=	opensaml2

.if !defined(OPENSAML2_BUILDLINK3_MK)
OPENSAML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opensaml2+=	opensaml2>=2.2.1
BUILDLINK_ABI_DEPENDS.opensaml2?=	opensaml2>=2.2.1nb1
BUILDLINK_PKGSRCDIR.opensaml2?=	../../wip/opensaml2

.include "../../security/openssl/buildlink3.mk"
.endif	# OPENSAML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-opensaml2
