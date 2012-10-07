# $NetBSD: Makefile,v 1.7 2012/10/07 15:20:25 asau Exp $
#

DISTNAME=		slackpkg2pkgsrc-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# none
COMMENT=		Simple script for easy generation of Slackware binary packages

PY_PATCHPLIST=		yes
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	slackpkg2pkgsrc.py

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${FILESDIR}/slackpkg2pkgsrc.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slackpkg2pkgsrc.py ${DESTDIR}${PREFIX}/bin/slackpkg2pkgsrc.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
