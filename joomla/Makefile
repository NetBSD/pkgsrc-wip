# $NetBSD: Makefile,v 1.1.1.1 2005/12/09 03:56:50 marmfield Exp $
#

DISTNAME=	${PKGNAME:S/-/_/}-Stable-Full_Package
PKGNAME=	joomla-1.0.4
CATEGORIES=	wip www
MASTER_SITES=	http://developer.joomla.org/sf/frs/do/downloadFile/projects.joomla/frs.joomla_1_0.1_0_4/frs2532?dl=1/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.joomla.org/
COMMENT=	Dynamic web content management system (CMS)

DEPENDS+=	php-mysql>=4.2.0:../../databases/php-mysql
DEPENDS+=	php-zlib>=4.2.0:../../archivers/php-zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MESSAGE_SUBST+=	PKGNAME_NOREV=${PKGNAME_NOREV:Q} \
		JOOMLA_CONFFILE=${JOOMLA_CONFFILE:Q}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

APACHE_USER?=	www
APACHE_GROUP?=	www
BUILD_DEFS+=	APACHE_USER APACHE_GROUP

EGDIR=			${PREFIX}/share/examples/joomla
JOOMLA_CONFDIR=		${PKG_SYSCONFDIR}/joomla
JOOMLA_CONFFILE=	${JOOMLA_CONFDIR}/joomla.conf
JOOMLA_DIR=		${PREFIX}/share/joomla

USE_PKGINSTALL=		yes
MAKE_DIRS=		${JOOMLA_CONFDIR}
CONF_FILES=		${EGDIR}/joomla.conf ${JOOMLA_CONFDIR}/joomla.conf
SPECIAL_PERMS=		${JOOMLA_CONFDIR}/joomla.conf ${APACHE_USER} \
			${APACHE_GROUP} 0644

NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	${TAR} -zxf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${WRKSRC}

do-configure:
	@${SED} -e "s|@JOOMLA_DIR@|${JOOMLA_DIR}|g" ${FILESDIR}/joomla.conf   \
			> ${WRKDIR}/joomla.conf

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

.include "../../mk/bsd.pkg.mk"
