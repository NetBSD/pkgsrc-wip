# $NetBSD: Makefile,v 1.1.1.1 2004/07/31 01:52:56 adrian_p Exp $

DISTNAME=	turba-1.2.2
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/turba/tarballs/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.horde.org/turba/
COMMENT=	Horde contact management application

DEPENDS+=	horde>=2.2.4:../../www/horde

DOCDIR=		${PREFIX}/share/doc/turba
EGDIR=		${PREFIX}/share/examples/turba
HORDEDIR=	${PREFIX}/share/horde
TURBADIR=	${HORDEDIR}/turba

MESSAGE_SUBST+=	TURBADIR=${TURBADIR}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR?=	httpd

SUBST_CLASSES=		paths
SUBST_STAGE.paths=	pre-install
SUBST_FILES.paths=	${FILESDIR}/turba.conf.dist
SUBST_SED.paths=	-e "s|@TURBADIR@|${TURBADIR}|g"
SUBST_MESSAGE.paths=	"Fixing paths."

CONF_FILES=	${EGDIR}/turba.conf ${PKG_SYSCONFDIR}/turba.conf
CONF_FILES+=	${TURBADIR}/config/conf.php.dist \
		${TURBADIR}/config/conf.php
SUPPORT_FILES+=	${TURBADIR}/config/attributes.php.dist \
		${TURBADIR}/config/attributes.php
SUPPORT_FILES+=	${TURBADIR}/config/html.php.dist \
		${TURBADIR}/config/html.php
SUPPORT_FILES+=	${TURBADIR}/config/menu.php.dist \
		${TURBADIR}/config/menu.php
SUPPORT_FILES+=	${TURBADIR}/config/prefs.php.dist \
		${TURBADIR}/config/prefs.php
SUPPORT_FILES+=	${TURBADIR}/config/sources.php.dist \
		${TURBADIR}/config/sources.php

do-build:
	@${FIND} ${WRKSRC} -name .htaccess -print | ${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name "*.pl" -print | ${XARGS} ${CHMOD} ${BINMODE}
	@${FIND} ${WRKSRC} -name "*.sh" -print | ${XARGS} ${CHMOD} ${BINMODE}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${TURBADIR}
	cd ${FILESDIR} && ${INSTALL_DATA} turba.conf.dist ${EGDIR}/turba.conf
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING README docs/* ${DOCDIR}
	cd ${WRKSRC} && ${CP} -R graphics lib locale po scripts \
		templates ${TURBADIR}
	${INSTALL_DATA_DIR} ${TURBADIR}/config
	cd ${WRKSRC}/config && ${INSTALL_DATA} * ${TURBADIR}/config
	cd ${WRKSRC} && ${INSTALL_DATA} *.php ${TURBADIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TURBADIR}
	${CHMOD} -R a-w ${TURBADIR}

.include "../../mk/bsd.pkg.mk"
