# $NetBSD: Makefile,v 1.1.1.1 2009/10/01 12:39:31 fhajny Exp $
#

DISTNAME=		mod_xsendfile-0.9
PKGNAME=		${APACHE_PKG_PREFIX}-${DISTNAME:S/mod_//}
CATEGORIES=		www
MASTER_SITES=		http://tn123.ath.cx/mod_xsendfile/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://tn123.ath.cx/mod_xsendfile/
COMMENT=		Apache 2 module that processes X-SENDFILE headers
LICENSE=		apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes

APACHE_MODULE=		YES
APACHE_MODULE_NAME=	mod_xsendfile.so

.include "../../mk/apache.mk"
BUILDLINK_API_DEPENDS.apache+=	apache>=2.0.47

do-build:
	cd ${WRKSRC} && ${APXS} -c ${APACHE_MODULE_NAME:S/.so//}.c

do-install:
	cd ${WRKSRC} && ${APXS} -i ${APACHE_MODULE_NAME:S/.so//}.la

.include "../../mk/bsd.pkg.mk"
