# $NetBSD$

BUILDLINK_TREE+=	sdl-hercules-softfloat

.if !defined(SDL_HERCULES_SOFTFLOAT_BUILDLINK3_MK)
SDL_HERCULES_SOFTFLOAT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.sdl-hercules-softfloat?=	build

BUILDLINK_API_DEPENDS.sdl-hercules-softfloat+=	sdl-hercules-softfloat>=3.5.0
BUILDLINK_PKGSRCDIR.sdl-hercules-softfloat?=	../../wip/sdl-hercules-softfloat
.endif	# SDL_HERCULES_SOFTFLOAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl-hercules-softfloat
