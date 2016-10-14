# $NetBSD$

PKGNAME=	simutrans-120.1.3
DISTNAME=	simutrans-src-120-1-3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=simutrans/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.simutrans.com/
COMMENT=	Simutrans is a freeware and open-source transportation simulator
LICENSE=	artistic

USE_TOOLS+=	pkg-config unzip gmake pax
USE_LANGUAGES=	c++ c

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	${WRKDIR}/configure.sh
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-pthread

WRKSRC=	${WRKDIR}

SUBST_CLASSES+=	testeq
SUBST_STAGE.testeq=	post-extract
SUBST_MESSAGE.testeq=	Replace non-portable "==" operator for test(1)
SUBST_FILES.testeq=	*.sh
SUBST_FILES.testeq+=	*/*.sh
SUBST_FILES.testeq+=	script/*.sh
SUBST_FILES.testeq+=	Makefile
SUBST_SED.testeq=	-e 's/==/=/g'

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin/
	cd ${WRKDIR} && ${PAX} -rw -pp simutrans ${DESTDIR}${PREFIX}/share/
	${INSTALL_PROGRAM} ${WRKDIR}/sim ${DESTDIR}${PREFIX}/bin/
	${FIND} ${DESTDIR}${PREFIX}/share -type f -exec ${CHMOD} 0644 {} \;

# url2pkg-marker (please do not remove this line.)
#.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
