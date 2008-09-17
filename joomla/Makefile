# $NetBSD: Makefile,v 1.13 2008/09/17 17:43:25 marttikuparinen Exp $

DISTNAME=	Joomla_1.5.7-Stable-Full_Package
PKGNAME=	joomla-1.5.7
CATEGORIES=	www
MASTER_SITES=	http://joomlacode.org/gf/download/frsrelease/8376/30991/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.joomla.org/
COMMENT=	Dynamic web content management system (CMS)

DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.10:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-zlib>=4.3.10:../../archivers/php-zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MESSAGE_SUBST+=		JOOMLA_CONFFILE=${JOOMLA_CONFFILE}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

APACHE_USER?=		www
APACHE_GROUP?=		www
BUILD_DEFS+=		APACHE_USER APACHE_GROUP

EGDIR=			${PREFIX}/share/examples/joomla
JOOMLA_CONFDIR=		${PKG_SYSCONFDIR}/joomla
JOOMLA_CONFFILE=	${JOOMLA_CONFDIR}/joomla.conf
JOOMLA_DIR=		${PREFIX}/share/joomla

MAKE_DIRS=		${JOOMLA_CONFDIR}
CONF_FILES=		${EGDIR}/joomla.conf ${JOOMLA_CONFDIR}/joomla.conf
SPECIAL_PERMS=		${JOOMLA_CONFDIR}/joomla.conf ${APACHE_USER} \
			${APACHE_GROUP} 0644

NO_CONFIGURE=		yes
NO_BUILD=		yes

# distfile does not extract to a subdirectory
# extract using bzip2 decompression to the WRKSRC subdirectory
EXTRACT_OPTS+=		-c bzip -d ${WRKSRC}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing pathnames in configuration file.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	../joomla.conf
SUBST_SED.paths=	-e "s,@JOOMLA_DIR@,${JOOMLA_DIR},g"

post-extract:
	${CP} ${FILESDIR}/joomla.conf ${WRKDIR}/joomla.conf

do-install:
	${INSTALL_DATA_DIR} ${JOOMLA_DIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC} && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} \
	    ${JOOMLA_DIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLA_DIR}/{} \;
	cd ${WRKSRC} && ${FIND} . \! -type d -exec ${INSTALL_DATA} {} \
	    ${JOOMLA_DIR}/{} \; -exec ${CHOWN} ${APACHE_USER}:${APACHE_GROUP} \
	    ${JOOMLA_DIR}/{} \;
	${INSTALL_DATA} ${WRKDIR}/joomla.conf ${EGDIR}/joomla.conf

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
