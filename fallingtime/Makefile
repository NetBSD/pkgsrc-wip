# $NetBSD$

DISTNAME=	FallingTime-${GITHUB_TAG}
PKGNAME=	fallingtime-${GITHUB_TAG}
CATEGORIES=	games
GITHUB_TAG=	1.0.1	
MASTER_SITES=	${MASTER_SITE_GITHUB:=cxong/}

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Arcade game inspired by Fall Down
HOMEPAGE=	https://github.com/cxong/FallingTime/
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	gtar
USE_LANGUAGES+=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	"-DINSTALL_PREFIX:PATH=${PREFIX}/libexec"
CMAKE_ARGS+=	"-DINSTALL_DATA_PREFIX:PATH=${PREFIX}/share/fallingtime"

WRKSRC=		${WRKDIR}/${DISTNAME}

pre-install:
	${SED} s,@@PREFIX@@,${PREFIX},g ${FILESDIR}/fallingtime.template > ${FILESDIR}/fallingtime
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/fallingtime ${DESTDIR}${PREFIX}/bin/fallingtime

pre-clean:
	${RM} -f ${FILESDIR}/fallingtime

.include "../../devel/SDL2/buildlink3.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
