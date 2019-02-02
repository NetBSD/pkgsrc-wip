# $NetBSD$

PKGNAME=	zlua-0.0.1
DISTNAME=	z.lua-${PKGVERSION_NOREV}
CATEGORIES=		shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=skywind3000/}
GITHUB_PROJECT=	z.lua
GITHUB_TAG=	ab8277f0cd1a0e6c3ef5dc306dec3f8f6718b664

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skywind3000/z.lua
COMMENT=	Tool which helps you navigate faster by learning your habits
LICENSE=	mit

# Upstream has no releases, so we don't use ${DISTNAME} here.
WRKSRC=	${WRKDIR}/z.lua-${GITHUB_TAG}

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/${PKGBASE}
INSTALLATION_DIRS+=		share/doc/${PKGBASE}


do-build:
	# do nothing

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/z.lua ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/z.lua.plugin.zsh ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.cn.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

	# z.cmd is a Batch/.bat script for Windows users. Not terribly useful for Unix-ey users, so into share/ it goes.
	${INSTALL_DATA} ${WRKSRC}/z.cmd ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../lang/lua/application.mk"
#.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
