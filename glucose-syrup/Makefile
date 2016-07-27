# $NetBSD$

DISTNAME=	glucose-syrup
PKGNAME=	glucose-syrup-4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.labri.fr/perso/lsimon/downloads/softwares/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.labri.fr/perso/lsimon/downloads/softwares/
COMMENT=	Parallel SAT solver
LICENSE=	glucose-syrup-license

USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${DISTNAME}/parallel
INSTALLATION_DIRS+=	bin

do-build:
	set -e; cd ${WRKSRC}; ${GMAKE} rs

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glucose-syrup_static ${DESTDIR}${PREFIX}/bin/glucose-syrup

USE_LANGUAGES=	c++

.include "../../mk/bsd.pkg.mk"
