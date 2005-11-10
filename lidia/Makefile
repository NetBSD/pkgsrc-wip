# $NetBSD: Makefile,v 1.1.1.1 2005/11/10 17:14:55 emil_s Exp $
#

DISTNAME=		LiDIA-2.1.3
PKGNAME=		lidia-2.1.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.informatik.tu-darmstadt.de/pub/TI/systems/LiDIA/current/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		ftp://ftp.informatik.tu-darmstadt.de/pub/TI/systems/LiDIA/current/
COMMENT=		C++ Library For Computational Number Theory

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-arithmetic=gmp

BUILD_DEPENDS+=		teTeX-[0-9]*:../../print/teTeX

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} != "NetBSD")
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
.endif

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}


post-build:
	cd ${WRKSRC} && ${GMAKE} doc && ${GMAKE} ps && ${GMAKE} pdf

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LiDIA.dvi ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LiDIA.ps  ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/LiDIA.pdf ${DOCDIR}


.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
