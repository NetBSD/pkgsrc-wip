# $NetBSD: Makefile,v 1.5 2005/01/30 19:17:19 schnoebe Exp $
#

DISTNAME=	avelsieve-1.9.1
PKGNAME=	squirrelmail-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Sieve Script editing plugin for SquirrelMail

NO_CONFIGURE=	# defined
USE_BUILDLINK3=	# defined

WRKSRC=		${WRKDIR}

SMDIR=			${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}

do-build:

do-install:
	cd ${WRKDIR} && ${TAR} -cf - ${DISTNAME:C/-.*$//} | \
		${TAR} -xf - -C ${SMDIR}/plugins

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
