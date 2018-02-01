# $NetBSD$

BUILDLINK_TREE+=	ksmtp

.if !defined(KSMTP_BUILDLINK3_MK)
KSMTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ksmtp+=	ksmtp>=17.12.1
BUILDLINK_PKGSRCDIR.ksmtp?=	../../wip/ksmtp

.include "../../devel/kio/buildlink3.mk"
.include "../../wip/kmime/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KSMTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ksmtp
