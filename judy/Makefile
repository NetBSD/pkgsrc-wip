# $NetBSD: Makefile,v 1.5 2012/09/24 16:56:26 asau Exp $
#

DISTNAME=	Judy-1.0.5
PKGNAME=	${DISTNAME:S/J/j/}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=judy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://judy.sourceforge.net/
COMMENT=	C library for efficient sparse arrays
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c

.include "../../mk/bsd.pkg.mk"
