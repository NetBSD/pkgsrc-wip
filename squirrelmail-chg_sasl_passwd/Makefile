# $NetBSD: Makefile,v 1.1.1.1 2005/01/30 19:16:19 schnoebe Exp $
#

DISTNAME=	chg_sasl_passwd-1.4-1.4.x
PKGNAME=	squirrelmail-${DISTNAME:C/-(.*)-.*$/-\1/}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	SASL password changing plugin for SquirrelMail

NO_CONFIGURE=	# defined
USE_BUILDLINK3=	# defined

WRKSRC=		${WRKDIR}

SMDIR=			${PREFIX}/share/squirrelmail
MESSAGE_SUBST+=		SMDIR=${SMDIR}

do-build:

do-install:
	cd ${WRKDIR} && ${TAR} -cf - ${DISTNAME:C/-.*$//} | \
		${TAR} -xf - -C ${SMDIR}/plugins

SUBST_CLASSES=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	chg_sasl_passwd/chgsaslpasswd.c
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	"Fixing harcoded paths."

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
