# $NetBSD: Makefile,v 1.8 2004/05/13 22:28:48 blef Exp $
#

DISTNAME=	geeklog-1.3.7sr1
PKGNAME=	geeklog-1.3.7
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.geeklog.net/
COMMENT=	Web content management

DEPENDS+=       {ap-php-4.[0-9]*,ap2-php-4.[0-9]*}:../../www/ap-php4
DEPENDS+=	mysql-server-[0-9]*:../../databases/mysql-server

NO_BUILD=	YES

APACHEDIR=	${PREFIX}/share/httpd/htdocs/

do-install:
	${INSTALL_DATA_DIR} ${APACHEDIR}/geeklog
	${CP} -R ${WRKSRC}/* ${APACHEDIR}/geeklog
	${CHOWN} -R www:www ${APACHEDIR}/geeklog
	${CHMOD} -R 755 ${APACHEDIR}/geeklog/logs
	${CHMOD} -R 755 ${APACHEDIR}/geeklog/public_html/backend

.include "../../mk/bsd.pkg.mk"
