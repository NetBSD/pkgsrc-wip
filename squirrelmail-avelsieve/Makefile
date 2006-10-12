# $NetBSD: Makefile,v 1.8 2006/10/12 02:59:26 schnoebe Exp $
#

DISTNAME=	avelsieve-1.9.7
PKGNAME=	squirrelmail-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Sieve Script editing plugin for SquirrelMail

NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}
USE_TOOLS+= tar

SMDIR=			${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}

do-build:
	cd ${WRKDIR} && \
	    ${FIND} . \( -name '*.bak' -o -name '.cvsignore' \) \
		-print | xargs rm

do-install:
	cd ${WRKDIR} && ${TAR} -cf - ${DISTNAME:C/-.*$//} | \
		${TAR} -xf - -C ${SMDIR}/plugins

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
