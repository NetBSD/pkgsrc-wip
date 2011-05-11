# $NetBSD: Makefile,v 1.4 2011/05/11 07:25:56 fhajny Exp $
#

DISTNAME=		mod_xsendfile-0.12
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		http://tn123.org/mod_xsendfile/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://tn123.org/mod_xsendfile/
COMMENT=		Apache 2 module that processes X-SENDFILE headers
LICENSE=		apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c
APACHE_MODULE_LA=	${DISTNAME:C|-.*||}.la

.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

do-build:
	cd ${WRKSRC} && ${APXS} ${CPPFLAGS} ${LDFLAGS} -c -o ${APACHE_MODULE_NAME} ${APACHE_MODULE_SRC}

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/httpd
	cd ${WRKSRC} && ${APXS} -i -S LIBEXECDIR=${DESTDIR}${PREFIX}/lib/httpd ${APACHE_MODULE_LA}

.include "../../mk/bsd.pkg.mk"
