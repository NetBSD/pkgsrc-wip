# $NetBSD: Makefile,v 1.4 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	pure-0.51
CATEGORIES=	lang
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://code.google.com/p/pure-lang/
COMMENT=	Modern-style functional programming language based on term rewriting
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake flex bison
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-release --without-elisp
PKGCONFIG_OVERRIDE=	pure.pc.in

.include "../../lang/clang/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
