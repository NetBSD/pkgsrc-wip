# $NetBSD$

GITHUB_PROJECT=	ja2-stracciatella
GITHUB_TAG=	v0.16.1
DISTNAME=	ja2-0.16.1
PKGNAME=	ja2-0.16.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ja2-stracciatella/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	astr0b4by@gmail.com
HOMEPAGE=	https://github.com/ja2-stracciatella/ja2-stracciatella/
COMMENT=	Improved, cross-platform, stable Jagged Alliance 2 runtime
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/ja2-stracciatella-0.16.1
USE_CMAKE=	yes
USE_TOOLS+=	bash msgfmt pkg-config pax
USE_LANGUAGES=	c c++14
USE_LIBTOOL=	yes
GCC_REQD+=	5

CXXFLAGS.NetBSD+=	-D_NETBSD_SOURCE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/games/ja2
INSTALLATION_DIRS+=	share/games/ja2/rust/release
pre-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/ja2.sh.in > ${WRKDIR}/ja2.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ja2.sh ${DESTDIR}${PREFIX}/bin/ja2
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/games/ja2
	cd ${WRKSRC} && \
	cp ja2 ${DESTDIR}${PREFIX}/share/games/ja2 | \
	mkdir ${DESTDIR}${PREFIX}/share/games/ja2/rust/release | \
        cp ${WRKSRC}/rust/release/libstracciatella.so \
	${DESTDIR}${PREFIX}/share/games/ja2/rust/release/ | \
	cp -R ${WRKSRC}/externalized ${DESTDIR}${PREFIX}/share/games/ja2 | \
        cp -R ${WRKSRC}/mods ${DESTDIR}${PREFIX}/share/games/ja2 | \
	cp -R ${WRKSRC}/unittests ${DESTDIR}${PREFIX}/share/games/ja2

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
