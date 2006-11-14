# $NetBSD: Makefile,v 1.15 2006/11/14 19:20:33 shattered Exp $

DISTNAME=	moregroupware-0.7.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.2${EXTRACT_SUFX} \
		moregroupware-docs-0.7.2${EXTRACT_SUFX} \
		moregroupware-addons-0.7.2${EXTRACT_SUFX} \
		moregroupware-scripts-0.7.2${EXTRACT_SUFX} \

MAINTAINER=	pih@xbase.dk
HOMEPAGE=	http://www.moregroupware.de/
COMMENT=	Web based GroupWare system

DEPENDS+=	php4-curl>=4.3.4:../../www/php-curl
DEPENDS+=	mysql4-server>=4.0.0:../../databases/mysql4-server
DEPENDS+=	php-ldap>=4.3.4:../../databases/php-ldap
DEPENDS+=	php-mysql>=4.3.4:../../databases/php-mysql
DEPENDS+=	php-gd>=4.3.4:../../graphics/php-gd

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware


do-install:
	${CP} -r ${WRKSRC} ${PREFIX}/share
	${CHOWN} -R www:www ${PREFIX}/share/moregroupware

.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
