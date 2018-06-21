# $NetBSD$

BUILDLINK_TREE+=	cinnamon-screensaver

.if !defined(CINNAMON_SCREENSAVER_BUILDLINK3_MK)
CINNAMON_SCREENSAVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-screensaver+=	cinnamon-screensaver>=3.8.1
BUILDLINK_PKGSRCDIR.cinnamon-screensaver?=	../../wip/cinnamon-screensaver

.endif	# CINNAMON_SCREENSAVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-screensaver
