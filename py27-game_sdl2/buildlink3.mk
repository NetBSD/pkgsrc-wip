# $NetBSD: buildlink3.mk,v 1.7 2025/10/23 20:36:36 wiz Exp $

BUILDLINK_TREE+=	py27-game_sdl2

.if !defined(PY_GAME_SDL2_BUILDLINK3_MK)
PY_GAME_SDL2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-game_sdl2+=	${PYPKGPREFIX}-game_sdl2>=2.1.0
BUILDLINK_ABI_DEPENDS.py27-game_sdl2?=	${PYPKGPREFIX}-game_sdl2>=2.1.0
BUILDLINK_PKGSRCDIR.py27-game_sdl2?=	../../wip/py27-game_sdl2

BUILDLINK_INCDIRS.py27-game_sdl2+=	${PYINC}/pygame_sdl2

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# PY_GAME_SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-game_sdl2
