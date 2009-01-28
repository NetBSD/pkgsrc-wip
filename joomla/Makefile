# $NetBSD: Makefile,v 1.18 2009/01/28 13:26:23 heidnes Exp $

DISTNAME=	Joomla_1.5.9-Stable-Full_Package
PKGNAME=	joomla-1.5.9
CATEGORIES=	www
MASTER_SITES=	http://joomlacode.org/gf/download/frsrelease/9294/34964/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.joomla.org/
COMMENT=	Dynamic web content management system (CMS)
#LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.10:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.3.10:../../archivers/php-zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/joomla
JOOMLADIR=		${PREFIX}/share/joomla

CONF_FILES=		${EGDIR}/joomla.conf ${PKG_SYSCONFDIR}/joomla.conf

NO_CONFIGURE=		yes
NO_BUILD=		yes

# distfile does not extract to a subdirectory
# extract using bzip2 decompression to the WRKSRC subdirectory
EXTRACT_OPTS+=		-c bzip -d ${WRKSRC}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../joomla.conf
SUBST_SED.paths=	-e "s,@JOOMLADIR@,${JOOMLADIR},g"

post-extract:
	${CP} ${FILESDIR}/joomla.conf ${WRKDIR}/joomla.conf
	${MV} ${WRKSRC}/installation ${WRKSRC}/installation.disabled

do-install:
	${INSTALL_DATA_DIR} ${JOOMLADIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	    ${JOOMLADIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	    ${JOOMLADIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLADIR}/{} \;
	${INSTALL_DATA} ${WRKDIR}/joomla.conf ${EGDIR}/joomla.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
