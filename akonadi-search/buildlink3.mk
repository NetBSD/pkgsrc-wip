# $NetBSD$

BUILDLINK_TREE+=	akonadi-search

.if !defined(AKONADI_SEARCH_BUILDLINK3_MK)
AKONADI_SEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-search+=	akonadi-search>=17.12.1
BUILDLINK_PKGSRCDIR.akonadi-search?=	../../wip/akonadi-search

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/krunner/buildlink3.mk"
.include "../../wip/akonadi-mime/buildlink3.mk"
.include "../../wip/kcalcore/buildlink3.mk"
.include "../../wip/kcontacts/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_SEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-search
