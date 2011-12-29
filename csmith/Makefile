# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:38:49 jihbed Exp $
#

DISTNAME=	csmith-2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://embed.cs.utah.edu/csmith/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://embed.cs.utah.edu/csmith/
COMMENT=	Random generator of C programs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gm4 gmake perl
USE_LANGUAGES=	c c++

REPLACE_PERL+=	scripts/compiler_test.pl scripts/launchn.pl scripts/test_csmith.pl \
					

.include "../../mk/bsd.pkg.mk"
