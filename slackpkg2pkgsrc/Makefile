# $NetBSD: Makefile,v 1.8 2014/01/25 10:45:28 thomasklausner Exp $
#

DISTNAME=		slackpkg2pkgsrc-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		# none
COMMENT=		Simple script for easy generation of Slackware binary packages

PY_PATCHPLIST=	yes
NO_BUILD=	yes
REPLACE_PYTHON=	slackpkg2pkgsrc.py

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${FILESDIR}/slackpkg2pkgsrc.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slackpkg2pkgsrc.py ${DESTDIR}${PREFIX}/bin/slackpkg2pkgsrc.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
