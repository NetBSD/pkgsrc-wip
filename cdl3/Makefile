# $NetBSD: Makefile,v 1.2 2004/01/25 02:11:44 grantbeattie Exp $
#

DISTNAME=		cdl3-1.2.4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.kun.nl/pub/cdl3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapboen@sci.kun.nl
HOMEPAGE=		http://www.cs.kun.nl/~kees/cdl3
COMMENT=		Programming language for the development of compilers

USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
