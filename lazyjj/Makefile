# $NetBSD$

DISTNAME=	lazyjj-0.5.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cretezy/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cretezy/lazyjj/
COMMENT=	TUI for Jujutsu/jj
LICENSE=	apache-2.0

DEPENDS+=	jj-[0-9]*:../../devel/jj

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
ANSI_TO_TUI_REV=	74bd97e76066186cace33ea04cf497055db67e62
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		ansi-to-tui-${ANSI_TO_TUI_REV}.tar.gz

SITES.ansi-to-tui-${ANSI_TO_TUI_REV}.tar.gz+=	-${MASTER_SITE_GITHUB:=Cretezy/}ansi-to-tui/archive/${ANSI_TO_TUI_REV}.tar.gz

USE_LANGUAGES=		c

RUST_REQ+=	1.80

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
