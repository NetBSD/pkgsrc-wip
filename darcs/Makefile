# $NetBSD: Makefile,v 1.5 2005/01/05 20:25:22 rillig Exp $
#

DISTNAME=		darcs-0.9.20
CATEGORIES=		devel
MASTER_SITES=		http://abridgegame.org/darcs/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://abridgegame.org/darcs/
COMMENT=		Advanced Revision Control System based on patches

BUILD_DEPENDS+=		latex2html-[0-9]*:../../textproc/latex2html

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
MAKEFLAGS+=		LDFLAGS=
MAKEFLAGS+=		CPPFLAGS=
MAKEFLAGS+=		MAKEMANUAL=${TRUE:Q}
MAKEFILE=		${WRKSRC}/GNUmakefile

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
