# $NetBSD$

DISTNAME=	z.lua-0.0.0.20190131
PKGNAME=	${DISTNAME:S/z.lua/zlua/}
CATEGORIES=		shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=skywind3000/}
GITHUB_PROJECT=	z.lua
GITHUB_TAG=	9fe0fc67a002ce122b10e85e047ef136a4544096

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skywind3000/z.lua
COMMENT=	Tool that lets you quickly jump around your filesystem
LICENSE=	mit

NO_BUILD=	yes

# Upstream has no releases, so we don't use ${DISTNAME} here.
WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/${PKGBASE}
INSTALLATION_DIRS+=		share/doc/${PKGBASE}


do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/z.lua ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/omz.plugin.zsh ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.cn.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

	# z.cmd is a Batch/.bat script for Windows users. Not terribly useful for Unix-ey users, so into share/ it goes.
	${INSTALL_DATA} ${WRKSRC}/z.cmd ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
