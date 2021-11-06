# $NetBSD$

BUILDLINK_TREE+=	hercules4sdl-telnet

.if !defined(HERCULES4SDL_TELNET_BUILDLINK3_MK)
HERCULES4SDL_TELNET_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-telnet?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-telnet+=	hercules4sdl-telnet>=2.5
BUILDLINK_PKGSRCDIR.hercules4sdl-telnet?=	../../wip/hercules4sdl-telnet
.endif	# HERCULES4SDL_TELNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-telnet
