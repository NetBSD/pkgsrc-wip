# $NetBSD: Makefile,v 1.5 2004/02/27 23:24:50 rillig Exp $
#

DISTNAME=	dbf-0.8.1.src
PKGNAME=	dbf-0.8.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbf.sourceforge.net/
COMMENT=	Converts dBASE files to comma separated values text files

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}

.include "../../mk/bsd.pkg.mk"
