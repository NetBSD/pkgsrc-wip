# $NetBSD$

DISTNAME=	lazyjj-0.2.1.20240815
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Cretezy/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	940ae464d468edbf12c5d953e36cde37aba5aef6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Cretezy/lazyjj/
COMMENT=	TUI for Jujutsu/jj
LICENSE=	apache-2.0

DEPENDS+=	jj-[0-9]*:../../devel/jj

USE_LANGUAGES=		c

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
