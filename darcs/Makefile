# $NetBSD: Makefile,v 1.7 2005/01/20 18:07:46 rillig Exp $
#

DISTNAME=		darcs-1.0.1
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Advanced Revision Control System based on patches

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
# latex2html currently does not work for me. :(
MAKEFLAGS+=		MAKEMANUAL=${TRUE:Q}
MAKEFILE=		${WRKSRC}/GNUmakefile

post-install:
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/${PKGBASE}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/${PKGBASE}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
