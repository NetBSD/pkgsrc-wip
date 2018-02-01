# $NetBSD$

BUILDLINK_TREE+=	kmailtransport

.if !defined(KMAILTRANSPORT_BUILDLINK3_MK)
KMAILTRANSPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmailtransport+=	kmailtransport>=17.12.1
BUILDLINK_PKGSRCDIR.kmailtransport?=	../../wip/kmailtransport

.include "../../wip/akonadi-mime/buildlink3.mk"
.include "../../wip/ksmtp/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMAILTRANSPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmailtransport
