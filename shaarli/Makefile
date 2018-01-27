# $NetBSD: Makefile,v 1.8 2013/04/21 13:55:39 triaxx Exp $
#

PKGNAME=	shaarli-${VERSION}
DISTNAME=	shaarli_${VERSION}
VERSION=	0.0.41beta
CATEGORIES=	www
MASTER_SITES=	http://sebsauvage.net/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	frederic@fauberteau.org
HOMEPAGE=	http://sebsauvage.net/wiki/doku.php?id=php:shaarli
COMMENT=	Shaarli is a minimalist delicious clone
LICENSE=	zlib

.include "../../lang/php/phpversion.mk"
DEPENDS+= ${PHP_PKG_PREFIX}-zlib-[0-9]*:../../archivers/php-zlib

USE_TOOLS+=	pax
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	shaarli

WWW_USER?=	${APACHE_USER}
WWW_GROUP?=	${APACHE_GROUP}

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER
BUILD_DEFS+=		WWW_USER WWW_GROUP APACHE_USER APACHE_GROUP VARBASE

RCDIR=		${PREFIX}/share/shaarli
EGDIR=		${PREFIX}/share/examples/shaarli
PAXDIRS=	images inc tpl

MESSAGE_SUBST+=	DOCDIR=${DOCDIR}
MESSAGE_SUBST+=	VARBASE=${VARBASE}

OWN_DIRS_PERMS+=	${VARBASE}/shaarli \
		       	${WWW_USER} ${WWW_GROUP} 0770
OWN_DIRS_PERMS+=	${VARBASE}/shaarli/data \
		       	${WWW_USER} ${WWW_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/shaarli/tmp \
		       	${WWW_USER} ${WWW_GROUP} 0750

CONF_FILES+=	${EGDIR}/apache.conf \
	       	${PKG_SYSCONFDIR}/apache.conf

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_FILES.files=	apache.conf.dist
SUBST_FILES.files+=	index.php
SUBST_SED.files=	-e "s|@RCDIR@|${RCDIR}|g"
SUBST_SED.files+=	-e "s|@DATADIR@|${VARBASE}/shaarli/data|g"
SUBST_SED.files+=	-e "s|@CACHEDIR@|${VARBASE}/shaarli/tmp|g"
SUBST_MESSAGE.files=	Fixing configuration files.

post-extract:
#	${MKDIR} ${WRKSRC}
#	${MV} ${WRKDIR}/index.php ${WRKSRC}
#.for d in ${PAXDIRS}
#		${MV} ${WRKDIR}/${d} ${WRKSRC}
#.endfor
	${CP} ${FILESDIR}/apache.conf.dist ${WRKSRC}/apache.conf.dist

INSTALLATION_DIRS+=	${RCDIR} ${EGDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${RCDIR}
.for d in ${PAXDIRS}
		${INSTALL_DATA_DIR} ${DESTDIR}${RCDIR}/${d}
.endfor
.for d in ${PAXDIRS}
		cd ${WRKSRC}/${d} && pax -rwpam . ${DESTDIR}${RCDIR}/${d}
.endfor
	${INSTALL_DATA} ${WRKSRC}/apache.conf.dist ${DESTDIR}${EGDIR}/apache.conf

.include "../../mk/bsd.pkg.mk"
