# $NetBSD$

BUILDLINK_TREE+=	sonnet

.if !defined(SONNET_BUILDLINK3_MK)
SONNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonnet+=	sonnet>=5.19.0
BUILDLINK_PKGSRCDIR.sonnet?=	../../wip/sonnet

#.include "../../textproc/aspell/buildlink3.mk"
#.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# SONNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonnet
