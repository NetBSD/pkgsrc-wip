# $NetBSD: Makefile,v 1.2 2011/09/27 21:32:20 crocusino Exp $
#

DISTNAME=	pure-0.47
CATEGORIES=	lang
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://code.google.com/p/pure-lang/
COMMENT=	Modern-style functional programming language based on term rewriting
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake flex bison
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-release --without-elisp

.include "../../lang/clang/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
