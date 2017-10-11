# $NetBSD$
PKGNAME=		elfhash-0.1
CATEGORIES=		devel

GIT_REPOSITORIES=		elfhash
GIT_REPO.elfhash=		git://github.com/cjacker/elfhash

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cjacker/elfhash
COMMENT=	Manipulate Hash tables in ELF files
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/elfhash

USE_LANGUAGES=	c

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/elfhash ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
