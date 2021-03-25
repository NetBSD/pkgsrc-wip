# $NetBSD$

BUILDLINK_TREE+=	messagelib

.if !defined(MESSAGELIB_BUILDLINK3_MK)
MESSAGELIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.messagelib+=	messagelib>=20.04.1
BUILDLINK_PKGSRCDIR.messagelib?=	../../wip/messagelib

.include "../../misc/kidentitymanagement/buildlink3.mk"
.include "../../wip/kmailtransport/buildlink3.mk"
.include "../../mail/kmbox/buildlink3.mk"
.include "../../wip/kdepim-apps-libs/buildlink3.mk"
.include "../../wip/libgravatar/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MESSAGELIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-messagelib
