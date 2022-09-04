# $NetBSD$

DISTNAME=	cromagrally-3.0.0
CATEGORIES=	games
GIT_REPO=	https://github.com/jorio/CroMagRally.git

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/cromag/
COMMENT=	Source port of Cro-Mag Rally from Pangea Software
LICENSE=	cc-by-sa-v4.0 # XXX Actually it's cc-nc-by-sa-v4.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/cromagrally/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/cromagrally.template > ${WRKDIR}/cromagrally

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cromagrally ${DESTDIR}${PREFIX}/bin/cromagrally
	${INSTALL_PROGRAM} ${WRKSRC}/CroMagRally ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/cromagrally/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
