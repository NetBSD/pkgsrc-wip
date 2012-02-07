# $NetBSD: Makefile,v 1.18 2012/02/07 07:43:37 noud4 Exp $

DISTNAME=	moregroupware-0.7.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.2${EXTRACT_SUFX} \
		moregroupware-docs-0.7.2${EXTRACT_SUFX} \
		moregroupware-addons-0.7.2${EXTRACT_SUFX} \
		moregroupware-scripts-0.7.2${EXTRACT_SUFX} \

MAINTAINER=	pih@xbase.dk
HOMEPAGE=	http://www.moregroupware.de/
COMMENT=	Web based GroupWare system

DEPENDS+=	${PHP_PKG_PREFIX}-curl>=4.3.4:../../www/php-curl
DEPENDS+=	mysql-server>=4.0.0:../../databases/mysql${MYSQL_VERSION_DEFAULT}-server
DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.3.4:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-mysql>=4.3.4:../../databases/php-mysql
DEPENDS+=	${PHP_PKG_PREFIX}-gd>=4.3.4:../../graphics/php-gd

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware


do-install:
	${CP} -r ${WRKSRC} ${PREFIX}/share
	${CHOWN} -R www:www ${PREFIX}/share/moregroupware

.include "../../lang/php/phpversion.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
