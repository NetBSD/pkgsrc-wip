# $NetBSD$

DISTNAME=	lazyjj-0.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cretezy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cretezy/lazyjj/
COMMENT=	TUI for Jujutsu/jj
LICENSE=	apache-2.0

DEPENDS+=	jj-[0-9]*:../../devel/jj

USE_LANGUAGES=		c

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
