# $NetBSD: Makefile,v 1.3 2008/05/19 21:35:18 athaba Exp $
#

PKGNAME=	gmp-${DISTNAME}
DISTNAME=	ecm-6.2
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/4663/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://ecm.gforge.inria.fr/
COMMENT=	Elliptic Curve Method for Integer Factorization

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
