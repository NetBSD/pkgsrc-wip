# $NetBSD: Makefile,v 1.3 2003/12/30 19:56:47 cjep Exp $
#

DISTNAME=	palm-db-tools-0_3_4
PKGNAME=	palm-db-tools-0.3.4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://palm-db-tools.sourceforge.net/
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
