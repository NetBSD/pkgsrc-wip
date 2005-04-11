# $NetBSD: Makefile,v 1.10 2005/04/11 21:14:06 tvierling Exp $

DISTNAME=	moregroupware-0.7.2
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.2${EXTRACT_SUFX} \
		moregroupware-docs-0.7.2${EXTRACT_SUFX} \
		moregroupware-addons-0.7.2${EXTRACT_SUFX} \
		moregroupware-scripts-0.7.2${EXTRACT_SUFX} \

MAINTAINER=	pih@xbase.dk
HOMEPAGE=	http://moregroupware.org/
COMMENT=	Web based GroupWare system

DEPENDS+=	php-curl>=4.3.4:../../www/php-curl
DEPENDS+=	mysql-server>=3.23:../../databases/mysql-server
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
