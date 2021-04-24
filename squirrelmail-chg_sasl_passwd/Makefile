# $NetBSD: Makefile,v 1.10 2013/01/20 22:39:01 schnoebe Exp $
#

DISTNAME=	chg_sasl_passwd-1.4-1.4.x
PKGNAME=	squirrelmail-${DISTNAME:C/-(.*)-.*$/-\1/}
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squirrelmail.org/
COMMENT=	SASL password changing plugin for SquirrelMail
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}

SMDIR=			${PREFIX}/share/squirrelmail
PIDIR=			${SMDIR}/plugins/${DISTNAME:C/-.*$//}

MESSAGE_SUBST+=		SMDIR=${SMDIR}
MESSAGE_SUBST+=		PIDIR=${PIDIR}

CONF_FILES=	${PIDIR}/config_default.php ${PIDIR}/config.php

do-build:
	cd ${WRKDIR}/${DISTNAME:C/-.*$//} ;\
	${MV} config.php config_default.php

do-install:
	${MKDIR} ${DESTDIR}${SMDIR}/plugins
	cd ${WRKDIR} && ${TAR} -cf - ${DISTNAME:C/-.*$//} | \
		${TAR} -xf - -C ${DESTDIR}${SMDIR}/plugins

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	chg_sasl_passwd/chgsaslpasswd.c
SUBST_SED.prefix+=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	Fixing harcoded paths.

.include "../../mail/squirrelmail/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
