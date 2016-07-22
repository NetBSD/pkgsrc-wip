# $NetBSD$

DISTNAME=	accelerator-0.1.1
PKGNAME=	${DISTNAME:S/accelerator/accelerator3d/}
CATEGORIES=	games
MASTER_SITES=	https://sourceforge.net/projects/accelerator3d/files/accelerator/0.1.1/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/accelerator3d/files/accelerator/0.1.1/
COMMENT=	Fast-paced, 3D, first-person shoot/dodge-'em-up
LICENSE=	artistic

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-ode-[0-9]*:../../wip/py-ode
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

REPLACE_PYTHON+=	accelerator.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-Numeric via py-OpenGL

NO_BUILD=	yes

ACCELERATOR3D_DATADIR=	${PREFIX}/share/${PKGBASE}

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	accelerator.py
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|'snd'|'${PREFIX}/share/${PKGBASE}'|"
SUBST_SED.prefix=	-e "s|'gfx'|'${PREFIX}/share/${PKGBASE}'|"
SUBST_STAGE.prefix=	pre-install

INSTALLATION_DIRS+=	bin share/${PKGBASE}

do-install:
	${RUN} ${INSTALL_SCRIPT} ${WRKSRC}/accelerator.py ${DESTDIR}${PREFIX}/bin/accelerator3d
	${RUN} ${INSTALL_DATA} ${WRKSRC}/snd/* ${DESTDIR}${ACCELERATOR3D_DATADIR}
	${RUN} ${INSTALL_DATA} ${WRKSRC}/gfx/* ${DESTDIR}${ACCELERATOR3D_DATADIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
