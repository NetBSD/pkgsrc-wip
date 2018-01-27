# $NetBSD$

PKGNAME=	simutrans-120.2.2
DISTNAME=	simutrans-src-120-2-2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simutrans/}
DISTFILES+=	language_pack-Base+texts.zip
SITES.language_pack-Base+texts.zip= \
		http://simutrans-germany.com/translator/data/tab/
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
SITES.${DISTNAME}${EXTRACT_SUFX}= \
		${MASTER_SITE_SOURCEFORGE:=simutrans/}120-2-2/${DISTNAME}${EXTRACT_SUFX}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.simutrans.com/
COMMENT=	Simutrans is a freeware and open-source transportation simulator
LICENSE=	artistic

USE_TOOLS+=	pkg-config unzip gmake pax grep
USE_LANGUAGES=	c++ c

DEPENDS+=	simutrans-data-0.1{,nb*}:../../wip/simutrans-data

GNU_CONFIGURE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/configure.sh

#This does nothing.
CONFIGURE_ARGS+=	--prefix=${PREFIX}/share/simutrans
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/bin
PTHREAD_OPTS+=		require
#CONFIGURE_ARGS+=	--with-pthread

#AUTO_MKDIRS=		yes
WRKSRC=			${WRKDIR}/simutrans

SUBST_CLASSES+=		testeq
SUBST_STAGE.testeq=	post-extract
SUBST_MESSAGE.testeq=	Replace non-portable "==" operator for test(1)
SUBST_FILES.testeq=	*.sh
SUBST_FILES.testeq+=	*/*.sh
SUBST_FILES.testeq+=	script/*.sh
SUBST_FILES.testeq+=	Makefile
SUBST_SED.testeq=	-e 's/==/=/g'


do-extract:
		unzip ${DISTDIR}/${DISTNAME}.zip -d ${WRKSRC} -o
		unzip ${DISTDIR}/language_pack-Base+texts.zip -d ${WRKSRC}/simutrans/text -o

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp simutrans ${DESTDIR}${PREFIX}/share/
	${MKDIR} ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/sim ${DESTDIR}${PREFIX}/bin/
	${SED} <${FILESDIR}/simutrans >${WRKSRC}/script/simutrans \
	-e "s,XXXPREFIXXXX,${PREFIX},g" \
	#${INSTALL_SCRIPT} ${FILESDIR}/simutrans ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/script/simutrans ${DESTDIR}${PREFIX}/bin/
	${FIND} ${DESTDIR}${PREFIX}/share -type f -exec ${CHMOD} 0644 {} \;

#.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
#.include "../../audio/timidity/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
