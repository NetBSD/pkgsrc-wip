# $NetBSD: Makefile,v 1.2 2004/06/10 01:50:20 xtraeme Exp $
#

DISTNAME=	WebSVN_139
PKGNAME=	websvn-1.39
CATEGORIES=	www
MASTER_SITES=	http://websvn.tigris.org/files/documents/1380/10659/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://websvn.tigris.org/
COMMENT=	SHORT_DESCRIPTION_OF_THE_PACKAGE

BUILD_DEPENDS+=	{apache-[0-9]*,apache6-[0-9]*,apache2-[0-9]*}
BUILD_DEPENDS+=	ap-php-[0-9]*:../../www/ap-php4

WRKSRC=		${WRKDIR}/WebSVN
NO_BUILD=	yes

MESSAGE_SUBST+=	PKGBASE=${PKGBASE}
MESSAGE_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}
PLIST_SUBST+=	HTTPD_ROOT=${HTTPD_ROOT}

HTTPD_ROOT?=	share/httpd/htdocs

BUILD_DEFS+=	HTTPD_ROOT

do-install:
	${INSTALL_DATA_DIR} ${HTTPD_ROOT}/websvn
	cd ${WRKSRC} && ${PAX} -rwppm . ${HTTPD_ROOT}/websvn

.include "../../mk/bsd.pkg.mk"
