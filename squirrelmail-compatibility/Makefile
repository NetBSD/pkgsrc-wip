# $NetBSD: Makefile,v 1.1.1.1 2005/02/04 21:46:56 schnoebe Exp $
#

DISTNAME=	compatibility-1.3
PKGNAME=	squirrelmail-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Previous version compatibility plugin for SquirrelMail

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
