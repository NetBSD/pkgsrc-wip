# $NetBSD$

BUILDLINK_TREE+=	hercules4sdl-decnumber

.if !defined(HERCULES4SDL_DECNUMBER_BUILDLINK3_MK)
HERCULES4SDL_DECNUMBER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-decnumber?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-decnumber+=	hercules4sdl-decnumber>=2.5
BUILDLINK_PKGSRCDIR.hercules4sdl-decnumber?=	../../wip/hercules4sdl-decnumber
.endif	# HERCULES4SDL_DECNUMBER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-decnumber
