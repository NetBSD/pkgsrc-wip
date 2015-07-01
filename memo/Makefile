# $NetBSD: Makefile,v 1.3 2015/07/01 03:04:24 cfkoch Exp $

DISTNAME=	memo-1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.getmemo.org/

MAINTAINER=	cfkoch@users.sourceforge.net
HOMEPAGE=	http://www.getmemo.org/
COMMENT=	Note-taking software
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
