# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 23:02:03 xtraeme Exp $

DISTNAME=	moregroupware-0.7.1
PKGNAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=moregroupware/}
DISTFILES=	moregroupware-core-0.7.1${EXTRACT_SUFX} \
		moregroupware-docs-0.7.1${EXTRACT_SUFX}

MAINTAINER=	david@netbsd-fr.org
COMMENT=	A web based GroupWare system
USE_BUILDLINK2=	YES

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/moregroupware

DEPENDS+=	ap-php>=4.3.4:../../www/ap-php4
DEPENDS+=	php-curl>=4.3.4:../../www/php4-curl
DEPENDS+=	php-ldap>=4.3.4:../../databases/php4-ldap
DEPENDS+=	php-mysql>=4.3.4:../../databases/php4-mysql
DEPENDS+=	php-gd>=4.3.4:../../graphics/php4-gd

do-install:
	${CP} -r ${WRKSRC} ${PREFIX}/share
	${CHOWN} -R www:www ${PREFIX}/share/moregroupware

.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
