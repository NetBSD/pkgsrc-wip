# $NetBSD: Makefile,v 1.2 2004/05/13 23:54:39 blef Exp $

DISTNAME=	moregroupware-0.7.1
PKGNAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.1${EXTRACT_SUFX} \
		moregroupware-docs-0.7.1${EXTRACT_SUFX}

MAINTAINER=	david@netbsd-fr.org
COMMENT=	A web based GroupWare system
USE_BUILDLINK3=	YES

DEPENDS+=	ap-php>=4.3.4:../../www/ap-php4
DEPENDS+=	php-curl>=4.3.4:../../www/php4-curl
DEPENDS+=	php-ldap>=4.3.4:../../databases/php4-ldap
DEPENDS+=	php-mysql>=4.3.4:../../databases/php4-mysql
DEPENDS+=	php-gd>=4.3.4:../../graphics/php4-gd

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware

do-install:
	${CP} -r ${WRKSRC} ${PREFIX}/share
	${CHOWN} -R www:www ${PREFIX}/share/moregroupware

.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
