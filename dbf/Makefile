# $NetBSD: Makefile,v 1.4 2004/01/25 02:11:57 grantbeattie Exp $
#

DISTNAME=	dbf-0.8.1.src
PKGNAME=	dbf-0.8.1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dbf.sourceforge.net/
COMMENT=	Converts dBASE files to comma separated values text files

USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}

.include "../../mk/bsd.pkg.mk"
