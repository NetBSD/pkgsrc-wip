# $NetBSD: Makefile,v 1.2 2015/06/21 17:00:51 thomasklausner Exp $

DISTNAME=	memo-1.6
CATEGORIES=	misc
MASTER_SITES=	http://www.getmemo.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.getmemo.org/
COMMENT=	Note-taking software
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
