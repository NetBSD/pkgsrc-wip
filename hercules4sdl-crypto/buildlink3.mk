# $NetBSD$

BUILDLINK_TREE+=	hercules4sdl-crypto

.if !defined(HERCULES4SDL_CRYPTO_BUILDLINK3_MK)
HERCULES4SDL_CRYPTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-crypto?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-crypto+=	hercules4sdl-crypto>=2.5
BUILDLINK_PKGSRCDIR.hercules4sdl-crypto?=	../../wip/hercules4sdl-crypto
.endif	# HERCULES4SDL_CRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-crypto
