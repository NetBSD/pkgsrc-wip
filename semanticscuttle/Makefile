# $NetBSD: Makefile,v 1.5 2012/11/16 18:26:10 kristerw Exp $
#

PKGNAME=	semanticscuttle-${VERSION}
DISTNAME=	SemanticScuttle-${VERSION}
VERSION=	0.98.3
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=semanticscuttle/}
EXTRACT_SUFX=	.zip

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://semanticscuttle.sourceforge.net/
COMMENT=	SemanticScuttle is a social bookmarking tool
LICENSE=	gnu-gpl-v2

.include "../../lang/php/phpversion.mk"
.include "../../mk/apache.mk"
DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}-[0-9]*:../../www/ap-php

USE_TOOLS+=	pax
#NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/semanticscuttle
EGDIR=		${PREFIX}/share/examples/semanticscuttle
SSDIR=		${PREFIX}/share/semanticscuttle
PAXDIRS=	scripts src www

CONF_FILES+=	${EGDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-build
SUBST_FILES.files=	apache.conf.dist
SUBST_SED.files=	-e "s|@SSHOME@|${SSDIR}/www|g"
SUBST_MESSAGE.files=	Fixing configuration files.

.include "options.mk"

do-build:
	${CP} ${FILESDIR}/apache.conf.dist ${WRKSRC}/apache.conf.dist
	${CP} ${FILESDIR}/pgsql.inittables.sql ${WRKSRC}/pgsql.inittables.sql

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

do-install:
.for d in ${PAXDIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${SSDIR}/${d}
.endfor
.for d in ${PAXDIRS}
	cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${SSDIR}/${d}
.endfor

	${INSTALL_DATA} ${WRKSRC}/apache.conf.dist ${DESTDIR}${EGDIR}/apache.conf
	${INSTALL_DATA} ${WRKSRC}/pgsql.inittables.sql ${DESTDIR}${EGDIR}/pgsql.inittables.sql

	# Data
.for d in data/locales data/schema data/templates
		${INSTALL_DATA_DIR} ${DESTDIR}${SSDIR}/${d}
.endfor
.for d in data/locales data/schema data/templates
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${SSDIR}/${d}
.endfor

	${INSTALL_DATA} ${WRKSRC}/data/config.default.php ${DESTDIR}${SSDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/config.php.dist ${DESTDIR}${EGDIR}/config.php
	${INSTALL_DATA} ${WRKSRC}/data/tables.sql ${DESTDIR}${EGDIR}/mysql.inittables.sql

	# Documentation
	cd ${WRKSRC}/doc && pax -rwpam . ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
