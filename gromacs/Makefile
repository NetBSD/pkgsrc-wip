# $NetBSD: Makefile,v 1.7 2008/05/30 11:24:37 asau Exp $
#

DISTNAME=		gromacs-3.3.3
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=		pih@xbase.dk
HOMEPAGE=		http://www.gromacs.org/
COMMENT=		Molecular dynamics package

PKG_DESTDIR_SUPPORT=	user-destdir

# Official recommendation is not to use the gcc 4.1.x set of compilers.

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-double --program-suffix=

#TEST_TARGET=		tests	# something extra needed?

.include "../../math/fftw/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../x11/lesstif/buildlink3.mk"
#.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
