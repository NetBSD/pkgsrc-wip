# $NetBSD: Makefile,v 1.4 2013/01/20 22:43:52 schnoebe Exp $
#

DISTNAME=	vlogin-3.5-1.2.7
PKGNAME=	squirrelmail-${DISTNAME:C/-(.*)-.*$/-\1/}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	Easy Virtual domain support plugin for SquirrelMail

DEPENDS+=	squirrelmail-compatibility>=1.3:../../wip/squirrelmail-compatibility


WRKSRC=		${WRKDIR}

SMDIR=			${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}

do-build:

do-install:
	${MKDIR} ${DESTDIR}${SMDIR}/plugins
	cd ${WRKDIR} && ${TAR} -cf - ${DISTNAME:C/-.*$//} | \
		${TAR} -xf - -C ${DESTDIR}${SMDIR}/plugins

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
