# $NetBSD$

BUILDLINK_TREE+=	libansilove

.if !defined(LIBANSILOVE_BUILDLINK3_MK)
LIBANSILOVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libansilove+=	libansilove>=1.1.2
BUILDLINK_PKGSRCDIR.libansilove?=	../../graphics/libansilove
.endif	# LIBANSILOVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libansilove
