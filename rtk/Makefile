# $NetBSD$

DISTNAME=	rtk-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=rtk-ai/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rtk-ai/rtk/
COMMENT=	CLI proxy that reduces LLM token consumption
# busl when CARGO_NO_DEFAULT_FEATURES is gone - pipeline command enabled
LICENSE=	apache-2.0 # AND busl-1.1-license

USE_LANGUAGES=	c

MAKE_ENV+=	RTK_EDITION=oss

CARGO_NO_DEFAULT_FEATURES=	yes

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
