# $NetBSD: Makefile,v 1.6 2004/04/25 08:46:37 blef Exp $
#

DISTNAME=	dbf-0.8.1.src
PKGNAME=	dbf-0.8.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbf.sourceforge.net/
COMMENT=	Converts dBASE files to comma separated values text files

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}

.include "../../mk/bsd.pkg.mk"
