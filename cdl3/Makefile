# $NetBSD: Makefile,v 1.1.1.1 2003/09/17 14:50:51 xtraeme Exp $
#

DISTNAME=		cdl3-1.2.4
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.cs.kun.nl/pub/cdl3/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jaapboen@sci.kun.nl
HOMEPAGE=		http://www.cs.kun.nl/~kees/cdl3
COMMENT=		Programming language for the development of compilers

USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
