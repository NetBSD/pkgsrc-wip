# $NetBSD: Makefile,v 1.2 2003/11/21 15:07:30 thomasklausner Exp $
#

DISTNAME=	dbf-0.8.1.src
PKGNAME=	dbf-0.8.1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbf/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://dbf.sourceforge.net/
COMMENT=	Converts dBASE files to comma separated values text files

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}

.include "../../mk/bsd.pkg.mk"
