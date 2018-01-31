# $NetBSD$

BUILDLINK_TREE+=	kldap

.if !defined(KLDAP_BUILDLINK3_MK)
KLDAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kldap+=	kldap>=17.12.1
BUILDLINK_PKGSRCDIR.kldap?=	../../wip/kldap

.include "../../textproc/kcompletion/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KLDAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-kldap
