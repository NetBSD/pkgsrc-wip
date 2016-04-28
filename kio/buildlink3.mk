# $NetBSD$

BUILDLINK_TREE+=	kio

.if !defined(KIO_BUILDLINK3_MK)
KIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kio+=	kio>=5.21.0
BUILDLINK_PKGSRCDIR.kio?=	../../wip/kio

.include "../../devel/zlib/buildlink3.mk"
.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/kbookmarks/buildlink3.mk"
.include "../../wip/kjobwidgets/buildlink3.mk"
.include "../../wip/kwallet/buildlink3.mk"
.include "../../wip/solid/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kio
