# $NetBSD: Makefile,v 1.5 2008/07/20 16:45:40 athaba Exp $
#

PKGNAME=	gmp-${DISTNAME}
DISTNAME=	ecm-6.2.1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/4663/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://ecm.gforge.inria.fr/
COMMENT=	Elliptic Curve Method for Integer Factorization

WRKSRC=			${WRKDIR}/ecm-6.2
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
