# $NetBSD$

BUILDLINK_TREE+=	ki18n

.if !defined(KI18N_BUILDLINK3_MK)
KI18N_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ki18n+=	ki18n>=5.18.0
BUILDLINK_PKGSRCDIR.ki18n?=	../../wip/ki18n

#.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KI18N_BUILDLINK3_MK

BUILDLINK_TREE+=	-ki18n
