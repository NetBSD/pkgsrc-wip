# $NetBSD: Makefile,v 1.9 2015/03/04 19:43:31 tnn2 Exp $
#

DISTNAME=	pure-0.64
CATEGORIES=	lang
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://purelang.bitbucket.org/
COMMENT=	Modern-style functional programming language based on term rewriting
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake flex bison
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-release --without-elisp
PKGCONFIG_OVERRIDE=	pure.pc.in

pre-configure:
	${LN} -s ${LLVM_CONFIG_PATH} ${TOOLS_DIR}/bin/llvm-config

.include "../../lang/libLLVM34/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
