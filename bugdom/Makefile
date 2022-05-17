# $NetBSD$

DISTNAME=	bugdom-1.3.1
CATEGORIES=	games
GIT_REPO=	https://github.com/jorio/Bugdom.git
GIT_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/bug/
COMMENT=	Pangea Software's Bugdom for modern systems
LICENSE=	cc-by-sa-v4.0 # XXX Actually it's cc-nc-by-sa-v4.0

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/bugdom/Data

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/bugdom.template > ${WRKDIR}/bugdom

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bugdom ${DESTDIR}${PREFIX}/bin/bugdom
	${INSTALL_PROGRAM} ${WRKSRC}/Bugdom ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/bugdom/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
