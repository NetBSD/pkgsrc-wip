# $NetBSD: Makefile,v 1.10 2006/05/19 16:51:29 ykomatsu Exp $
#

DISTNAME=	palm-db-tools-0_3_4
PKGNAME=	palm-db-tools-0.3.4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://palm-db-tools.sourceforge.net/
COMMENT=	Tools to convert to/from Palm OS databases

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	${WRKSRC}/configure

WRKSRC=		${WRKDIR}/palm-db-tools

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
