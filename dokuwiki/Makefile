# $NetBSD: Makefile,v 1.2 2013/06/25 10:04:45 triaxx Exp $
#

PKGVERSION=	20130510
DISTVERSION=	2013-05-10a
PKGNAME=	dokuwiki-${PKGVERSION}
DISTNAME=	dokuwiki-${DISTVERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.splitbrain.org/_media/projects/dokuwiki/
EXTRACT_SUFX=	.tgz

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://www.dokuwiki.org/
COMMENT=	DokuWiki is a standards compliant, simple to use Wiki
LICENSE=	gnu-gpl-v2

.include "../../lang/php/phpversion.mk"

USE_TOOLS+=	pax
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	dokuwiki

WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP VARBASE

DOKUDIR=	${PREFIX}/share/dokuwiki
DOCDIR=		${PREFIX}/share/doc/dokuwiki
EGDIR=		${PREFIX}/share/examples/dokuwiki
RESDIR=		${PREFIX}/share/resources/dokuwiki
PAXDIRS=	bin inc lib

# Data directory
OWN_DIRS_PERMS+=	${VARBASE}/dokuwiki ${WWW_USER} ${WWW_GROUP} 0750
.for d in attic cache index locks media_attic media_meta meta tmp
OWN_DIRS_PERMS+=	${VARBASE}/dokuwiki/${d} ${WWW_USER} ${WWW_GROUP} 0750
CONF_FILES_PERMS+=	${RESDIR}/_dummy ${VARBASE}/dokuwiki/${d}/_dummy ${WWW_USER} ${WWW_GROUP} 0640
.endfor
.for d in media media/wiki pages pages/playground pages/wiki
OWN_DIRS_PERMS+=	${VARBASE}/dokuwiki/${d} ${WWW_USER} ${WWW_GROUP} 0750
.endfor
CONF_FILES_PERMS+=	${RESDIR}/_dummy ${VARBASE}/dokuwiki/_dummy ${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${RESDIR}/dokuwiki-128.png ${VARBASE}/dokuwiki/media/wiki/dokuwiki-128.png ${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${RESDIR}/playground.txt ${VARBASE}/dokuwiki/pages/playground/playground.txt ${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${RESDIR}/dokuwiki.txt ${VARBASE}/dokuwiki/pages/wiki/dokuwiki.txt ${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${RESDIR}/syntax.txt ${VARBASE}/dokuwiki/pages/wiki/syntax.txt ${WWW_USER} ${WWW_GROUP} 0640
CONF_FILES_PERMS+=	${RESDIR}/security.png ${VARBASE}/dokuwiki/security.png ${WWW_USER} ${WWW_GROUP} 0640
# Configuration directory
OWN_DIRS_PERMS+=	${DOKUDIR}/conf ${WWW_USER} ${ROOT_GROUP} 0750
CONF_FILES_PERMS+=	${EGDIR}/conf/acl.auth.php.dist ${DOKUDIR}/conf/acl.auth.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/local.php.dist ${DOKUDIR}/conf/local.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/users.auth.php.dist ${DOKUDIR}/conf/users.auth.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/dokuwiki.php ${DOKUDIR}/conf/dokuwiki.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/mediameta.php ${DOKUDIR}/conf/mediameta.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/plugins.php ${DOKUDIR}/conf/plugins.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/plugins.required.php ${DOKUDIR}/conf/plugins.required.php \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/acronyms.conf ${DOKUDIR}/conf/acronyms.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/entities.conf ${DOKUDIR}/conf/entities.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/interwiki.conf ${DOKUDIR}/conf/interwiki.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/mime.conf ${DOKUDIR}/conf/mime.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/scheme.conf ${DOKUDIR}/conf/scheme.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/smileys.conf ${DOKUDIR}/conf/smileys.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/conf/wordblock.conf ${DOKUDIR}/conf/wordblock.conf \
			${WWW_USER} ${ROOT_GROUP} 0640
CONF_FILES_PERMS+=	${EGDIR}/apache.conf ${PKG_SYSCONFDIR}/apache.conf \
			${WWW_USER} ${WWW_GROUP} 0640

REPLACE_INTERPRETER+=	php
REPLACE.php.old=	.*/bin/php
REPLACE.php.new=	${PREFIX}/bin/php
REPLACE_FILES.php=	bin/dwpage.php bin/indexer.php bin/render.php bin/striplangs.php bin/wantedpages.php

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files+=	conf/dokuwiki.php
SUBST_FILES.files+=	apache.conf.dist
SUBST_FILES.files+=	dokuser
SUBST_SED.files+=	-e "s|@DATADIR@|${VARBASE}/dokuwiki|g"
SUBST_SED.files+=	-e "s|@DOKUDIR@|${DOKUDIR}|g"
SUBST_MESSAGE.files=	Fixing configuration files.

MESSAGE_SUBST+=		DOKUDIR=${DOKUDIR}
MESSAGE_SUBST+=		VARBASE=${VARBASE}
MESSAGE_SUBST+=		EGDIR=${EGDIR}

post-extract:
	${CP} ${FILESDIR}/apache.conf.dist ${WRKSRC}/apache.conf.dist
	${CP} ${FILESDIR}/dokuser ${WRKSRC}/dokuser
	${FIND} ${WRKSRC} -name ".htaccess" -delete

INSTALLATION_DIRS+=	${DOKUDIR} ${DOCDIR} ${EGDIR}/conf ${RESDIR}

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${DOKUDIR}
	${INSTALL_DATA} ${WRKSRC}/doku.php  ${DESTDIR}${DOKUDIR}
	${INSTALL_DATA} ${WRKSRC}/feed.php  ${DESTDIR}${DOKUDIR}
.for d in ${PAXDIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOKUDIR}/${d}
	cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${DOKUDIR}/${d}
.endfor
	# Documentation
	${INSTALL_DATA} ${WRKSRC}/COPYING            ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README             ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION            ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/data/deleted.files ${DESTDIR}${DOCDIR}
	# Configuration
	${INSTALL_DATA} ${WRKSRC}/apache.conf.dist \
		        ${DESTDIR}${EGDIR}/apache.conf
	cd ${WRKSRC}/conf && pax -rwpam . ${DESTDIR}${EGDIR}/conf
	# Resources
.for f in data/_dummy data/media/wiki/dokuwiki-128.png \
	  data/pages/playground/playground.txt \
	  data/pages/wiki/dokuwiki.txt data/pages/wiki/syntax.txt \
	  data/security.png
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${RESDIR}
.endfor
	# Utils
	${INSTALL_SCRIPT} ${WRKSRC}/dokuser ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
