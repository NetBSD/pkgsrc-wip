# $NetBSD: Makefile,v 1.9 2015/03/04 19:43:31 tnn2 Exp $

DISTNAME=	pure-lang-0.68
PKGNAME=	${DISTNAME:S/-lang//}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=agraef/}
GITHUB_PROJECT=	pure-lang
GITHUB_TAG=	01603c49f8aab295989e2e239568373c3b016298

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	https://agraef.github.io/pure-lang/
#HOMEPAGE=	https://github.com/agraef/pure-lang
COMMENT=	Modern-style functional programming language based on term rewriting
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake flex bison autoconf automake autoreconf
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-optimized
CONFIGURE_ARGS+=	--enable-targets=host-only
CONFIGURE_ARGS+=	--without-elisp
PKGCONFIG_OVERRIDE=	pure/pure.pc.in
CONFIGURE_DIRS=		pure

# bombs on rpath check for some reason, but the rpath is present?
CHECK_SHLIBS_SKIP+=	bin/pure

pre-configure:
	${LN} -sf ${LLVM_CONFIG_PATH} ${TOOLS_DIR}/bin/llvm-config
	cd ${WRKSRC}/pure && ${TOOLS_PATH.autoreconf} -vif

.include "../../wip/libLLVM35/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
