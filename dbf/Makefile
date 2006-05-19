# $NetBSD: Makefile,v 1.9 2006/05/19 16:51:15 ykomatsu Exp $
#

DISTNAME=	dbf-0.8.1.src
PKGNAME=	dbf-0.8.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dbf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbf.sourceforge.net/
COMMENT=	Converts dBASE files to comma separated values text files

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
BUILD_DIRS=	${WRKSRC}/src
INSTALL_DIRS=	${WRKSRC}

.include "../../mk/bsd.pkg.mk"
