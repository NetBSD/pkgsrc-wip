# $NetBSD$

DISTNAME=	hypatia-0.3.3
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_GITHUB:=hypatia-engine/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hypatia-engine.github.io/
COMMENT=	2D RPG game engine written in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow

USE_TOOLS+=	perl
CHECK_PORTABILITY_SKIP+=	distrib.sh

post-extract:
	@cd ${WRKSRC} && perl -pi -e 's/\r$$//' setup.py

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/hypatia-demo ${DESTDIR}${PREFIX}/bin/hypatia-demo
	perl -pi -e "s,PREFIX,${PREFIX},g" \
		${DESTDIR}${PREFIX}/bin/hypatia-demo
	perl -pi -e "s,PYTHONBIN,${PYTHONBIN},g" \
		${DESTDIR}${PREFIX}/bin/hypatia-demo
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/hypatia/resources
	${INSTALL_SCRIPT} ${WRKSRC}/demo/game.py ${DESTDIR}${PREFIX}/share/examples/hypatia
	cd ${WRKSRC}/demo/resources && find * -type d -exec ${INSTALL_DATA_DIR} \
		"${DESTDIR}${PREFIX}/share/examples/hypatia/resources/{}" \;
	cd ${WRKSRC}/demo/resources && find * -type f -exec ${INSTALL_DATA} \
		"{}" "${DESTDIR}${PREFIX}/share/examples/hypatia/resources/{}" \;

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
