# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 10:19:02 xtraeme Exp $
#

DISTNAME=	geeklog-1.3.7sr1
PKGNAME=	geeklog-1.3.7
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.geeklog.net/
COMMENT=	Web content management 

DEPENDS+=	ap-php-[0-9]*:../../www/ap-php4	
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql-server

USE_BUILDLINK2=	YES
NO_BUILD=	YES

APACHEDIR=	${PREFIX}/share/httpd/htdocs/

do-install:

	${MKDIR} ${APACHEDIR}/geeklog
	${CP} -R ${WRKSRC}/* ${APACHEDIR}/geeklog
	${CHOWN} -R www:www ${APACHEDIR}/geeklog
	${CHMOD} -R 755 ${APACHEDIR}/geeklog/logs
	${CHMOD} -R 755 ${APACHEDIR}/geeklog/public_html/backend

.include "../../mk/bsd.pkg.mk"
