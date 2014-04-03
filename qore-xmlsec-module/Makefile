# $NetBSD: Makefile,v 1.3 2014/04/03 11:35:37 nros Exp $

DISTNAME=	qore-xmlsec-module-0.0.2
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	XMLSec module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran
PTHREAD_OPTS+=	require

CONFIGURE_ARGS+=--with-xmlsec-dir=${BUILDLINK_PREFIX.xmlsec1}
CONFIGURE_ARGS+=--with-libxml2-dir=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=--with-qore-dir=${BUILDLINK_PREFIX.qore}

INSTALLATION_DIRS+=     share/qore/docs/modules/xmlsec/html
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/xmlsec-module-doc.html \
		${DESTDIR}${PREFIX}/share/qore/docs/modules/xmlsec/html

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
