# $NetBSD: Makefile,v 1.2 2008/02/02 16:22:41 athaba Exp $
#

PKGNAME=	gmp-${DISTNAME}
DISTNAME=	ecm-6.1.3
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/2752/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://ecm.gforge.inria.fr/
COMMENT=	Elliptic Curve Method for Integer Factorization

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
