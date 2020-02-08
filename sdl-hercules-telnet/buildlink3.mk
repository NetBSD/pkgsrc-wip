# $NetBSD$

BUILDLINK_TREE+=	sdl-hercules-telnet

.if !defined(SDL_HERCULES_TELNET_BUILDLINK3_MK)
SDL_HERCULES_TELNET_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.sdl-hercules-telnet?=	build

BUILDLINK_API_DEPENDS.sdl-hercules-telnet+=	sdl-hercules-telnet>=1.0.0
BUILDLINK_PKGSRCDIR.sdl-hercules-telnet?=	../../wip/sdl-hercules-telnet
.endif	# SDL_HERCULES_TELNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl-hercules-telnet
