# $NetBSD: Makefile,v 1.5 2004/02/17 02:56:30 blef Exp $
#

DISTNAME=	palm-db-tools-0_3_4
PKGNAME=	palm-db-tools-0.3.4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://palm-db-tools.sourceforge.net/
COMMENT=	Tools to convert to/from Palm OS databases

USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	${WRKSRC}/configure

WRKSRC=		${WRKDIR}/palm-db-tools

.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
