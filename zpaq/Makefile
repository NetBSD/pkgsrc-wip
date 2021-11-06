# $NetBSD$

DISTNAME=		zpaq715
PKGNAME=		zpaq-7.15
CATEGORIES=		archivers
MASTER_SITES=		http://mattmahoney.net/dc/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mattmahoney.net/dc/zpaq.html
COMMENT=		Incremental Journaling Backup Utility and Archiver
LICENSE=		mit

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
USE_TOOLS+=		gmake pod2man pax
USE_LANGUAGES=		c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

SUBST_CLASSES+=		fix-env
SUBST_STAGE.fix-env=	pre-build
SUBST_MESSAGE.fix-env=	Fixing environment.
SUBST_FILES.fix-env=	Makefile
SUBST_SED.fix-env=	-e 's|CXXFLAGS=.*|CXXFLAGS=${CXXFLAGS}|'
SUBST_SED.fix-env+=	-e 's|PREFIX=.*|PREFIX=${PREFIX}|'
SUBST_SED.fix-env+=	-e 's|MANDIR=.*|MANDIR=$$(PREFIX)/man|'

NOT_PAX_MPROTECT_SAFE+=	bin/zpaq

.include "../../mk/bsd.pkg.mk"
