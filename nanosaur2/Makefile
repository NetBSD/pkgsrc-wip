# $NetBSD$

DISTNAME=	nanosaur2-2.1.0
CATEGORIES=	games
GIT_REPO=	https://github.com/jorio/Nanosaur2.git
GIT_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://jorio.itch.io/nanosaur2
COMMENT=	Source port of Nanosaur 2: Hatchling from Pangea Software
LICENSE=	cc-by-nc-sa-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/nanosaur2/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/nanosaur2.template > ${WRKDIR}/nanosaur2

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nanosaur2 ${DESTDIR}${PREFIX}/bin/nanosaur2
	${INSTALL_PROGRAM} ${WRKSRC}/Nanosaur2 ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nanosaur2/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
