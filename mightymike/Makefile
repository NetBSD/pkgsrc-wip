# $NetBSD$

DISTNAME=	mightymike-3.0.0
CATEGORIES=	games
GIT_REPO=	https://github.com/jorio/MightyMike.git
GIT_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.pangeasoft.net/nano/index.html
COMMENT=	Pangea Software's Mighty Mike (Power Pete) for modern systems
LICENSE=	cc-by-sa-v4.0 # XXX Actually it's cc-nc-by-sa-v4.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/mightymike/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/mightymike.template > ${WRKDIR}/mightymike

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mightymike ${DESTDIR}${PREFIX}/bin/mightymike
	${INSTALL_PROGRAM} ${WRKSRC}/MightyMike ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/mightymike/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
