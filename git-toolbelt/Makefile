# $NetBSD$

DISTNAME=	git-toolbelt-1.7.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nvie/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nvie/git-toolbelt/
COMMENT=	Suite of useful Git commands
LICENSE=	modified-bsd

DEPENDS+=	git-base-[0-9]*:../../devel/git-base

REPLACE_SH+=	git-*

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	bin share/doc/git-toolbelt

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/git-toolbelt
	${INSTALL_SCRIPT} ${WRKSRC}/git-* ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
