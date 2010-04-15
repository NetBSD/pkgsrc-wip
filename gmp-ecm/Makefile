# $NetBSD: Makefile,v 1.7 2010/04/15 07:10:05 athaba Exp $
#

PKGNAME=	gmp-${DISTNAME}
DISTNAME=	ecm-6.2.2
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/4663/

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	http://ecm.gforge.inria.fr/
COMMENT=	Elliptic Curve Method for Integer Factorization
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/ecm-6.2
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}

# Figure out how to use the libtool-stuff
#USE_LIBTOOL=		YES

TEST_TARGET=		check
PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
