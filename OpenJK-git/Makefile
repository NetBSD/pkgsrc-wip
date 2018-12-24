# $NetBSD$

DISTNAME=	OpenJK-0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=JACoders/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JACoders/OpenJK/
COMMENT=	Game engine for Jedi Academy and Jedi Outcast
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=		-DBuildJK2SPEngine:BOOL=YES
CMAKE_ARGS+=		-DBuildJK2SPGame:BOOL=YES
CMAKE_ARGS+=		-DBuildJK2SPRdVanilla:BOOL=YES
CMAKE_ARGS+=		-DBuildMPCGame:BOOL=YES
CMAKE_ARGS+=		-DBuildMPDed:BOOL=YES
CMAKE_ARGS+=		-DBuildMPEngine:BOOL=YES
CMAKE_ARGS+=		-DBuildMPGame:BOOL=YES
CMAKE_ARGS+=		-DBuildMPRdVanilla:BOOL=YES
CMAKE_ARGS+=		-DBuildMPUI:BOOL=YES
CMAKE_INSTALL_PREFIX=	${PREFIX}/share
GIT_REPOSITORIES=	OpenJK
GIT_REPO.OpenJK=	git://github.com/JACoders/OpenJK.git
INSTALLATION_DIRS+=	bin
PLIST_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH}
WRKSRC=			${WRKDIR}/OpenJK

post-build:
	${SED} -e s,@PREFIX@,${PREFIX}, -e s/@MACHINE_ARCH@/${MACHINE_ARCH}/ ${FILESDIR}/openjk.sh > ${WRKSRC}/openjk
	${SED} -e s,@PREFIX@,${PREFIX}, -e s/@MACHINE_ARCH@/${MACHINE_ARCH}/ ${FILESDIR}/openjk_sp.sh > ${WRKSRC}/openjk_sp
	${SED} -e s,@PREFIX@,${PREFIX}, -e s/@MACHINE_ARCH@/${MACHINE_ARCH}/ ${FILESDIR}/openjkded.sh > ${WRKSRC}/openjkded
	${SED} -e s,@PREFIX@,${PREFIX}, -e s/@MACHINE_ARCH@/${MACHINE_ARCH}/ ${FILESDIR}/openjo_sp.sh > ${WRKSRC}/openjo_sp

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/openjk ${DESTDIR}${PREFIX}/bin/openjk
	${INSTALL_SCRIPT} ${WRKSRC}/openjk_sp ${DESTDIR}${PREFIX}/bin/openjk_sp
	${INSTALL_SCRIPT} ${WRKSRC}/openjkded ${DESTDIR}${PREFIX}/bin/openjkded
	${INSTALL_SCRIPT} ${WRKSRC}/openjo_sp ${DESTDIR}${PREFIX}/bin/openjo_sp

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
