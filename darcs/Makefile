# $NetBSD: Makefile,v 1.10 2005/02/25 15:02:13 thomasklausner Exp $
#

DISTNAME=		darcs-1.0.1
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Advanced Revision Control System based on patches

BUILD_DEPENDS+=		teTeX-bin>=1.0:../../print/teTeX-bin
BUILD_DEPENDS+=		latex2html-[0-9]*:../../textproc/latex2html

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
MAKEFILE=		${WRKSRC}/GNUmakefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/${PKGBASE}/

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
