# $NetBSD: Makefile,v 1.4 2005/07/27 16:29:50 thomasklausner Exp $
#

DISTNAME=		slackpkg2pkgsrc-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		# none
COMMENT=		Simple script for easy generation of Slackware binary packages

PY_PATCHPLIST=		yes
NO_BUILD=		# defined
PYTHON_PATCH_SCRIPTS=	slackpkg2pkgsrc.py

do-extract:
	${CP} ${FILESDIR}/slackpkg2pkgsrc.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slackpkg2pkgsrc.py ${PREFIX}/bin/slackpkg2pkgsrc.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
