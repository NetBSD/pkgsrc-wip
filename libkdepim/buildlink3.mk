# $NetBSD$

BUILDLINK_TREE+=	libkdepim

.if !defined(LIBKDEPIM_BUILDLINK3_MK)
LIBKDEPIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdepim+=	libkdepim>=17.12.1
BUILDLINK_PKGSRCDIR.libkdepim?=	../../wip/libkdepim

.include "../../wip/akonadi-contacts/buildlink3.mk"
.include "../../wip/akonadi-search/buildlink3.mk"
.include "../../wip/kldap/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDEPIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdepim
