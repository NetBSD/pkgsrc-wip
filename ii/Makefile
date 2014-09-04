# $NetBSD: Makefile,v 1.1 2014/09/04 13:07:44 yrmt Exp $

DISTNAME=	ii-1.7
CATEGORIES=	chat
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	yrmt@users.sourceforge.net
HOMEPAGE=	http://dl.suckless.org/tools/
COMMENT=	Minimalist FIFO and filesystem-based IRC client
LICENSE=	mit

# Adjust config.mk
SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing config.mk
SUBST_FILES.makefile=	config.mk
SUBST_SED.makefile=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.makefile+=	-e 's,share/man,${PKGMANDIR},g'

.include "../../mk/bsd.pkg.mk"
