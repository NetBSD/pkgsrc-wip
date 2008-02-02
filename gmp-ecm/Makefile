# $NetBSD: Makefile,v 1.1.1.1 2008/02/02 12:27:15 athaba Exp $
#

DISTNAME=	ecm-6.1.3
CATEGORIES=	wip math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/2752/

MAINTAINER=	athaba@inode.at
HOMEPAGE=	http://ecm.gforge.inria.fr/
COMMENT=	Elliptic Curve Method for Integer Factorization

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-gmp-lib=${BUILDLINK_LIBDIRS.gmp} \
			--with-gmp-include=${BUILDLINK_INCDIRS.gmp}

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
