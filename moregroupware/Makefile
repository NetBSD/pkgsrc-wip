# $NetBSD: Makefile,v 1.5 2004/05/19 12:05:57 peterih Exp $

DISTNAME=	moregroupware-0.7.2
PKGNAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.2${EXTRACT_SUFX} \
		moregroupware-docs-0.7.2${EXTRACT_SUFX} \
		moregroupware-addons-0.7.2${EXTRACT_SUFX} \
		moregroupware-scripts-0.7.2${EXTRACT_SUFX} \

MAINTAINER=	pih@bsdmail.dk
HOMEPAGE=	http://moregroupware.org/
COMMENT=	Web based GroupWare system

DEPENDS+=	ap-php>=4.3.4:../../www/ap-php4
DEPENDS+=	php-curl>=4.3.4:../../www/php4-curl
DEPENDS+=	mysql-server>=3.23:../../databases/mysql-server
DEPENDS+=	php-ldap>=4.3.4:../../databases/php4-ldap
DEPENDS+=	php-mysql>=4.3.4:../../databases/php4-mysql
DEPENDS+=	php-gd>=4.3.4:../../graphics/php4-gd

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware

USE_BUILDLINK3=	YES

do-install:
	${CP} -r ${WRKSRC} ${PREFIX}/share
	${CHOWN} -R www:www ${PREFIX}/share/moregroupware

.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
