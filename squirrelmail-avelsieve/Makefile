# $NetBSD: Makefile,v 1.1.1.1 2005/01/30 18:13:30 schnoebe Exp $
#

DISTNAME=	avelsieve-1.9.1
PKGNAME=	squirrelmail-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Sieve Script editing plugin for SquirrelMail

NO_CONFIGURE=	# defined
USE_BUILDLINK3=	# defined

WRKSRC=		${WRKDIR}

do-build:

do-install:
	cd ${WRKDIR} && ${TAR} -cf - avelsieve | \
		${TAR} -xf - -C ${PREFIX}/share/squirrelmail/plugins

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
