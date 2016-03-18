# $NetBSD$

DISTNAME=	parafly-r2013-01-21
PKGNAME=	parafly-2013.01.21
CATEGORIES=	wip
MASTER_SITES=	https://sourceforge.net/projects/parafly/files/latest/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/parafly
COMMENT=	Process the commands in parallel on a single server
LICENSE=	original-bsd

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PKG_BINDIR}
USE_LANGUAGES=		c++
CFLAGS+=		-fPIC -fopenmp -DUSE_OPENMP

.include "../../mk/bsd.pkg.mk"
