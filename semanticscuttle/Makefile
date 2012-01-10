# $NetBSD: Makefile,v 1.1.1.1 2012/01/10 10:09:14 triaxx Exp $
#

PKGNAME=      semanticscuttle-${VERSION}
DISTNAME=     SemanticScuttle-${VERSION}
VERSION=      0.98.3
CATEGORIES=   www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=semanticscuttle/}
EXTRACT_SUFX= .zip

MAINTAINER=   frederic@fauberteau.org
HOMEPAGE=     http://semanticscuttle.sourceforge.net/
COMMENT=      SemanticScuttle is a social bookmarking tool
LICENSE=      gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/phpversion.mk"
.include "../../mk/apachever.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}:../../www/ap-php

USE_TOOLS+= pax
#NO_BUILD=   yes

DOCDIR=  ${PREFIX}/share/doc/semanticscuttle
EGDIR=   ${PREFIX}/share/examples/semanticscuttle
SSDIR=   ${PREFIX}/share/semanticscuttle
PAXDIRS= data scripts src www

CONF_FILES+= ${EGDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf

SUBST_CLASSES+=      files
SUBST_STAGE.files=   post-build
SUBST_FILES.files=   apache.conf.dist
SUBST_SED.files=     -e "s|@SSHOME@|${SSDIR}/www|g"
SUBST_MESSAGE.files= Fixing configuration files.

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/apache.conf.dist ${WRKSRC}/apache.conf.dist

INSTALLATION_DIRS+= ${DOCDIR} ${EGDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/apache.conf.dist ${DESTDIR}${EGDIR}/apache.conf
	${INSTALL_DATA} ${WRKSRC}/data/config.php.dist ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${WRKSRC}/data/tables.sql ${DESTDIR}${EGDIR}/mysql.inittables.sql

	${RM} ${WRKSRC}/data/config.php.dist
	${RM} ${WRKSRC}/data/tables.sql

.for d in ${PAXDIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${SSDIR}/${d}
.endfor
.for d in ${PAXDIRS}
	cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${SSDIR}/${d}
.endfor

	${FIND} ${WRKSRC}/docs/* -type f -print | ${XARGS} ${INSTALL_DATA} ${DESTDIR}${DOCDIR}
	${FIND} ${WRKSRC}/docs/* -type d -print | ${XARGS} ${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
