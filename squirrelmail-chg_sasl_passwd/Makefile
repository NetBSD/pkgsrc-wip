# $NetBSD: Makefile,v 1.3 2005/04/09 04:30:34 schnoebe Exp $
#

DISTNAME=	chg_sasl_passwd-1.4-1.4.x
PKGNAME=	squirrelmail-${DISTNAME:C/-(.*)-.*$/-\1/}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	SASL password changing plugin for SquirrelMail

NO_CONFIGURE=	YES
USE_BUILDLINK3=	# defined
USE_PKGINSTALL=YES

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}

SMDIR=			${PREFIX}/share/squirrelmail
PIDIR=			${SMDIR}/plugins/${DISTNAME:C/-.*$//}

MESSAGE_SUBST+=		SMDIR=${SMDIR}
MESSAGE_SUBST+=		PIDIR=${PIDIR}

CONF_FILES=     ${PIDIR}/config_default.php ${PIDIR}/config.php

do-build:
	cd ${WRKDIR}/${DISTNAME:C/-.*$//} ;\
	${MV} config.php config_default.php

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
