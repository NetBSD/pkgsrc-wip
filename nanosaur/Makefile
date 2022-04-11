# $NetBSD$

DISTNAME=	nanosaur-1.4.3
CATEGORIES=	games
GIT_REPO=	https://github.com/jorio/Nanosaur.git
GIT_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	dressupgeekout@gmail.com
HOMEPAGE=	https://www.pangeasoft.net/nano/index.html
COMMENT=	Source port of Nanosaur from Pangea Software
LICENSE=	cc-by-sa-v4.0 # XXX Actually it's cc-nc-by-sa-v4.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/nanosaur/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/nanosaur.template > ${WRKDIR}/nanosaur

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/nanosaur ${DESTDIR}${PREFIX}/bin/nanosaur
	${INSTALL_PROGRAM} ${WRKSRC}/Nanosaur ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/nanosaur/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
