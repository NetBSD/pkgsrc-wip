# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 16:21:01 xtraeme Exp $
#

DISTNAME=	palm-db-tools-0_3_4
PKGNAME=	palm-db-tools-0.3.4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://palm-db-tools.sourceforge.net
COMMENT=	Tools to convert to/from Palm OS databases

USE_GMAKE=	yes
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE=${WRKSRC}/libtool

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	${WRKSRC}/configure

WRKSRC=		${WRKDIR}/palm-db-tools

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
