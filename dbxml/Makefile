# $NetBSD: Makefile,v 1.1.1.1 2003/12/26 21:27:47 minskim Exp $

DISTNAME=	dbxml-1.2.0
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://www.sleepycat.com/products/xml.shtml
COMMENT=	Native XML data manager built on Berkeley DB

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}
CONFIGURE_ARGS+=	--with-pathan=${BUILDLINK_PREFIX.libpathan}

.include "../../databases/db4/buildlink2.mk"
.include "../../wip/libpathan/buildlink2.mk"
.include "../../textproc/xerces-c/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
