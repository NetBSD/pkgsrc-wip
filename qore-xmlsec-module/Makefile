# $NetBSD: Makefile,v 1.1 2014/01/28 16:16:33 nros Exp $

DISTNAME=	qore-xmlsec-module-0.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
