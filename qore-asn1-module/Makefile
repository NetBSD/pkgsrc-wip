# $NetBSD: Makefile,v 1.1 2014/02/22 15:01:31 nros Exp $

DISTNAME=	qore-asn1-module-0.0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	ASN.1 Qore module
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

INSTALLATION_DIRS+=     share/qore/docs/modules/asn1/html
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/asn1-module-doc.html \
		${DESTDIR}${PREFIX}/share/qore/docs/modules/asn1/html

.include "options.mk"
.include "../../wip/qore/module.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
