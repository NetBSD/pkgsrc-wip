# $NetBSD: buildlink2.mk,v 1.3 2003/11/18 00:54:40 marc Exp $
#

.if !defined(PYGAME_BUILDLINK2_MK)
PYGAME_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pygame
BUILDLINK_DEPENDS.pygame?=		${PYPKGPREFIX}-game>=1.6
BUILDLINK_PKGSRCDIR.pygame?=		../../wip/py-game

EVAL_PREFIX+=	BUILDLINK_PREFIX.pygame=${PYPKGPREFIX}-game
BUILDLINK_PREFIX.pygame_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.pygame+=	${PYINC}/pygame/*.h

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"

BUILDLINK_TARGETS+=	pygame-buildlink

pygame-buildlink: _BUILDLINK_USE

.endif	# PYGAME_BUILDLINK2_MK
