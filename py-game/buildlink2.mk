# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/19 20:29:55 marc Exp $
#

.if !defined(PY22PTH_GAME_BUILDLINK2_MK)
PY22PTH_GAME_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pygame
BUILDLINK_DEPENDS.pygame?=		${PYPKGPREFIX}-game>=1.5.6
BUILDLINK_PKGSRCDIR.pygame?=		../../wip/py-game

EVAL_PREFIX+=	BUILDLINK_PREFIX.pygame=${PYPKGPREFIX}-game
BUILDLINK_PREFIX.pygame_DEFAULT=	${LOCALBASE}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"

BUILDLINK_TARGETS+=	pygame-buildlink

py22pth-game-buildlink: _BUILDLINK_USE

.endif	# PY22PTH_GAME_BUILDLINK2_MK
