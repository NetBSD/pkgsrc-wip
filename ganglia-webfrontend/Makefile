# $NetBSD: Makefile,v 1.1 2009/10/25 16:08:18 brook1 Exp $
#

DISTNAME=	ganglia-3.1.2
PKGNAME=	ganglia-webfrontend-3.0.1
CATEGORIES=	www parallel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ganglia/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ganglia.sourceforge.net/
COMMENT=	PHP based frontend for the Ganglia Cluster Monitor

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${APACHE_PKG_PREFIX}-${PHP_PKG_PREFIX}>=4.1:../../www/ap-php
DEPENDS+=	ganglia-monitor-core>=3.0.1:../../parallel/ganglia-monitor-core

USE_TOOLS+=	pax

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${DISTNAME}/web/

DOCROOT=	${PREFIX}/share/httpd/htdocs/ganglia
MESSAGE_SUBST+=	PREFIX=${PREFIX} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	${DOCROOT}

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX
SUBST_FILES.prefix=	conf.php
SUBST_VARS.prefix=	PREFIX

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${DOCROOT}/
	${RM} ${DESTDIR}${DOCROOT}/AUTHORS
	${RM} ${DESTDIR}${DOCROOT}/COPYING
	${RM} ${DESTDIR}${DOCROOT}/Makefile.am
	${RM} ${DESTDIR}${DOCROOT}/conf.php.in
	${RM} ${DESTDIR}${DOCROOT}/conf.php.orig
	${RM} ${DESTDIR}${DOCROOT}/templates/default/footer.tpl.orig
	${RM} ${DESTDIR}${DOCROOT}/version.php.in

.include "../../mk/apachever.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
