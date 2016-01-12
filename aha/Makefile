# $NetBSD$

DISTNAME=	aha-0.4.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=theZiz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=theZiz/aha/}
COMMENT=	Ansi HTML Adapter
# It's not specified what version of LGPL
LICENSE=	mpl-1.1 OR gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

MAKE_ENV+=	MANDIR=${PKGMANDIR:Q}
MAKE_ENV+=	MANMODE=${MANMODE:Q}
MAKE_ENV+=	BINMODE=${BINMODE:Q}

.include "../../mk/bsd.pkg.mk"
