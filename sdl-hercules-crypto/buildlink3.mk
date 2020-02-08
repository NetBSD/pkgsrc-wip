# $NetBSD$

BUILDLINK_TREE+=	sdl-hercules-crypto

.if !defined(SDL_HERCULES_CRYPTO_BUILDLINK3_MK)
SDL_HERCULES_CRYPTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.sdl-hercules-crypto?=	build

BUILDLINK_API_DEPENDS.sdl-hercules-crypto+=	sdl-hercules-crypto>=1.0.0
BUILDLINK_PKGSRCDIR.sdl-hercules-crypto?=	../../wip/sdl-hercules-crypto
.endif	# SDL_HERCULES_CRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl-hercules-crypto
