# $NetBSD: Makefile,v 1.6 2014/03/07 16:26:40 jgoamakf Exp $
#

DISTNAME=	pure-0.59
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
FETCH_USING=	curl

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://purelang.bitbucket.org/
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
