# $NetBSD$

GITHUB_PROJECT=	doas
DISTNAME=	6.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Execute commands as another user
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/doas-6.1

ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*

SUBST_CLASSES+= 	fix-paths
SUBST_STAGE.fix-paths=	pre-install
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=	Makefile
SUBST_SED.fix-paths=	-e 's,$$(PREFIX)/man,$$(PKGMANDIR),g'
SUBST_SED.fix-paths=	-e 's,$$(PREFIX),$$(DESTDIR)$$(PREFIX),g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
