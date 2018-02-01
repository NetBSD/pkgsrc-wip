# $NetBSD$

BUILDLINK_TREE+=	akonadi-notes

.if !defined(AKONADI_NOTES_BUILDLINK3_MK)
AKONADI_NOTES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-notes+=	akonadi-notes>=17.12.1
BUILDLINK_PKGSRCDIR.akonadi-notes?=	../../wip/akonadi-notes

.include "../../wip/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_NOTES_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-notes
