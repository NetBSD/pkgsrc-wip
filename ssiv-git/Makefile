# $NetBSD$

DISTNAME=	ssiv-0.0.0
CATEGORIES=	games
GIT_REPO=	https://git.disroot.org/multiSnow/ssiv.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.disroot.org/multiSnow/ssiv
COMMENT=	Simple SDL Image Viewer
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-SDL2>=0.9.15:../../devel/py-SDL2
DEPENDS+=	${PYPKGPREFIX}-wand>=0.6.11:../../graphics/py-wand

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	bin

post-build:
	${ECHO} '#!/bin/sh' > ${WRKDIR}/ssiv.sh
	${ECHO} "${PYTHONBIN}"' -m ssiv "$$@"' >> ${WRKDIR}/ssiv.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ssiv.sh ${DESTDIR}${PREFIX}/bin/ssiv-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
