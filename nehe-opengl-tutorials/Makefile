# $NetBSD: Makefile,v 1.5 2005/05/24 10:31:12 rillig Exp $
#

DISTNAME=	nehe-opengl-tutorials-${NEHE_OPENGL_TUT_FLAVOUR}-0
WRKSRC=		${WRKDIR}
CATEGORIES=	graphics
MASTER_SITES=	http://nehe.gamedev.net/data/lessons/linux${NEHE_OPENGL_TUT_FLAVOUR}/ \
		http://nehe.gamedev.net/files/resources/
DISTFILES=	lesson01.tar.gz lesson02.tar.gz lesson03.tar.gz \
		lesson04.tar.gz lesson05.tar.gz lesson06.tar.gz \
		lesson07.tar.gz lesson08.tar.gz lesson09.tar.gz \
		lesson10.tar.gz lesson11.tar.gz lesson12.tar.gz \
		lesson16.tar.gz lesson17.tar.gz \
		lesson18.tar.gz lesson19.tar.gz lesson20.tar.gz \
		lesson21.tar.gz lesson22.tar.gz lesson23.tar.gz \
		lesson24.tar.gz lesson25.tar.gz lesson32.tar.gz \
		lesson36.tar.gz lesson37.tar.gz lesson40.tar.gz \
		lesson41.tar.gz lesson42.tar.gz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://nehe.gamedev.net/
COMMENT=		OpenGL tutorials from NeHe.gamedev.net - ${NEHE_OPENGL_TUT_FLAVOUR} versions

DIST_SUBDIR=   		nehe-opengl-tutorials-${NEHE_OPENGL_TUT_FLAVOUR}
USE_TOOLS+=		gmake
USE_X11=		yes
RESTRICTED=		"I am not sure if we can redistribute it"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

# other available on site: (empty) for GLut and "glx" for GLX

NEHE_OPENGL_TUT_FLAVOUR?=	sdl
NEHE_OPENGL_TUT_DIR?=		share/${DISTNAME}

.if ${NEHE_OPENGL_TUT_FLAVOUR} == "sdl"
# Those lessons are available for sdl, but there are compile trouble with 
# them, that I haven't yet solved:
#
# lesson13.tar.gz
# lesson43.tar.gz
# 
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk" # for lesson 21
.else
.error "Flavour ${NEHE_OPENGL_TUT_FLAVOUR} unknown!"
# 
# In case you want to create new Flavour: remember:
# not found in SDL, but propably found in GLX are:
# lesson14.tar.gz lesson15.tar.gz lesson26.tar.gz lesson27.tar.gz 	
# lesson28.tar.gz lesson29.tar.gz lesson30.tar.gz lesson31.tar.gz
# lesson33.tar.gz lesson34.tar.gz lesson35.tar.gz lesson38.tar.gz
# lesson39.tar.gz lesson44.tar.gz lesson45.tar.gz lesson46.tar.gz
# lesson47.tar.gz lesson48.tar.gz
#
# Please remember, that distinfo and patches should be set according
# to NEHE_OPENGL_TUT_FLAVOUR
#
.endif

do-build:
	cd ${WRKSRC} && for a in [Ll]esson*; do \
		cd $$a && ${GMAKE} && cd ..; done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${NEHE_OPENGL_TUT_DIR}
	cd ${WRKSRC} && ${PAX} -rw -pe [Ll]esson* ${PREFIX}/${NEHE_OPENGL_TUT_DIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${PREFIX} && ${FIND} ${NEHE_OPENGL_TUT_DIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${NEHE_OPENGL_TUT_DIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
