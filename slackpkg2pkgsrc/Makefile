# $NetBSD: Makefile,v 1.2 2004/03/15 13:41:34 cubidou Exp $
#

DISTNAME=		slackpkg2pkgsrc-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		pkgtools
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		# none
COMMENT=		Simple script for easy generation of Slackware binary packages

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
NO_BUILD=		# defined
PYTHON_PATCH_SCRIPTS=	slackpkg2pkgsrc.py

do-extract:
	${CP} ${FILESDIR}/slackpkg2pkgsrc.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/slackpkg2pkgsrc.py ${PREFIX}/bin/slackpkg2pkgsrc.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
