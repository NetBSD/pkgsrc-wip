# $NetBSD$

BUILDLINK_TREE+=	sdl-hercules-decnumber

.if !defined(SDL_HERCULES_DECNUMBER_BUILDLINK3_MK)
SDL_HERCULES_DECNUMBER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.sdl-hercules-decnumber?=	build

BUILDLINK_API_DEPENDS.sdl-hercules-decnumber+=	sdl-hercules-decnumber>=3.68.0
BUILDLINK_PKGSRCDIR.sdl-hercules-decnumber?=	../../wip/sdl-hercules-decnumber
.endif	# SDL_HERCULES_DECNUMBER_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl-hercules-decnumber
