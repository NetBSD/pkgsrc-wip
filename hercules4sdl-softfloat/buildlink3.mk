# $NetBSD$

BUILDLINK_TREE+=	hercules4sdl-softfloat

.if !defined(HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK)
HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-softfloat?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-softfloat+=	hercules4sdl-softfloat>=2.5
BUILDLINK_PKGSRCDIR.hercules4sdl-softfloat?=	../../wip/hercules4sdl-softfloat
.endif	# HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-softfloat
