# $NetBSD: Makefile,v 1.1 2015/08/18 20:24:52 yhardy Exp $

DISTNAME=	brogue-1.7.5
CATEGORIES=	games
MASTER_SITES=	-https://sites.google.com/site/broguegame/brogue-1.7.5-linux-amd64.tbz2?attredirects=0&d=1
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sites.google.com/site/broguegame/
COMMENT=	Brogue is a modern Roguelike game
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/brogue-1.7.5
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake
USE_NCURSES=	yes
USE_GAMESGROUP=	yes

SRCS=	src/libtcod-1.5.2/src/bresenham_c.c \
	src/libtcod-1.5.2/src/bsp_c.c \
	src/libtcod-1.5.2/src/color_c.c \
	src/libtcod-1.5.2/src/console_c.c \
	src/libtcod-1.5.2/src/fov_c.c \
	src/libtcod-1.5.2/src/fov_circular_raycasting.c \
	src/libtcod-1.5.2/src/fov_diamond_raycasting.c \
	src/libtcod-1.5.2/src/fov_permissive2.c \
	src/libtcod-1.5.2/src/fov_recursive_shadowcasting.c \
	src/libtcod-1.5.2/src/fov_restrictive.c \
	src/libtcod-1.5.2/src/heightmap_c.c \
	src/libtcod-1.5.2/src/image_c.c \
	src/libtcod-1.5.2/src/lex_c.c \
	src/libtcod-1.5.2/src/list_c.c \
	src/libtcod-1.5.2/src/mersenne_c.c \
	src/libtcod-1.5.2/src/namegen_c.c \
	src/libtcod-1.5.2/src/noise_c.c \
	src/libtcod-1.5.2/src/parser_c.c \
	src/libtcod-1.5.2/src/path_c.c \
	src/libtcod-1.5.2/src/png/lodepng.c \
	src/libtcod-1.5.2/src/sys_c.c \
	src/libtcod-1.5.2/src/sys_opengl_c.c \
	src/libtcod-1.5.2/src/sys_sdl_c.c \
	src/libtcod-1.5.2/src/sys_sdl_img_bmp.c \
	src/libtcod-1.5.2/src/sys_sdl_img_png.c \
	src/libtcod-1.5.2/src/tree_c.c \
	src/libtcod-1.5.2/src/txtfield_c.c \
	src/libtcod-1.5.2/src/wrappers.c \
	src/libtcod-1.5.2/src/zip_c.c \
	src/brogue/Architect.c \
	src/brogue/Buttons.c \
	src/brogue/Combat.c \
	src/brogue/Dijkstra.c \
	src/brogue/Globals.c \
	src/brogue/Grid.c \
	src/brogue/IO.c \
	src/brogue/Items.c \
	src/brogue/Light.c \
	src/brogue/MainMenu.c \
	src/brogue/Monsters.c \
	src/brogue/Movement.c \
	src/brogue/PowerTables.c \
	src/brogue/Random.c \
	src/brogue/Recordings.c \
	src/brogue/RogueMain.c \
	src/brogue/Sqrt.c \
	src/brogue/Time.c \
	src/platform/curses-platform.c \
	src/platform/main.c \
	src/platform/platformdependent.c \
	src/platform/tcod-platform.c \
	src/platform/term.c

CFLAGS+=	-I ${WRKSRC}/src/brogue
CFLAGS+=	-I ${WRKSRC}/src/platform
CFLAGS+=	-I ${WRKSRC}/src/libtcod-1.5.2/include
CFLAGS+=	-I ${BUILDLINK_PREFIX.ncurses}/${BUILDLINK_INCDIRS.ncurses}
CFLAGS+=	-DBROGUE_CURSES
CFLAGS+=	-DBROGUE_TCOD
CFLAGS+=	-DBROGUE_SHARE=\"${PREFIX}/share/brogue/\"
CFLAGS+=	${DL_CFLAGS}
LDFLAGS+=	${DL_LDFLAGS} ${DL_LIBS}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/brogue
INSTALLATION_DIRS+=	share/brogue/fonts

REQD_FILES_PERMS+=	share/brogue/BrogueHighScores.empty \
			share/brogue/BrogueHighScores.txt \
			${GAMEDATA_PERMS}

do-build:
	mkdir ${WRKSRC}/build
	for i in ${SRCS}; do \
		j=$${i%.c}.o; k=$${j##*/}; \
		${ECHO} CC: $$i; \
		${CC} -c -o ${WRKSRC}/build/$$k ${CFLAGS} ${WRKSRC}/$$i || exit 1; \
	done
	${CC} -o ${WRKSRC}/bin/brogue ${WRKSRC}/build/*.o ${LDFLAGS} -lncurses -lSDL -lGL -lz

do-install:
	${INSTALL_GAME} ${WRKSRC}/bin/brogue ${DESTDIR}${PREFIX}/bin
	${INSTALL_GAME_DATA} ${WRKSRC}/bin/BrogueHighScores.txt ${DESTDIR}${PREFIX}/share/brogue/BrogueHighScores.empty
	for i in ${WRKSRC}/bin/fonts/*; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/share/brogue/fonts; \
	done

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
