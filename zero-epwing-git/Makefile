# $NetBSD$

PKGNAME=	zero-epwing-0.1
CATEGORIES=	textproc
GIT_REPO=	git://github.com/FooSoft/zero-epwing.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FooSoft/zero-epwing
COMMENT=	Tool that converts EPWING files to JSON
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c99 c++

USE_TOOLS+=	gmake perl # required for the bundled libeb

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zero-epwing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
