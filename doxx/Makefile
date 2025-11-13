# $NetBSD$

DISTNAME=	doxx-0.1.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgreenwell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bgreenwell/doxx/
COMMENT=	Show contents of .docx files on the terminal
LICENSE=	mit

USE_LANGUAGES=	c

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
