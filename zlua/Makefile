# $NetBSD$

DISTNAME=	z.lua-1.8.4
PKGNAME=	${DISTNAME:S/z.lua/zlua/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=skywind3000/}
GITHUB_PROJECT=	z.lua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skywind3000/z.lua
COMMENT=	Lightweight tool that lets you quickly jump around your filesystem
LICENSE=	mit

NO_BUILD=	yes
REPLACE_LUA+=	z.lua

# Upstream has no releases, so we don't use ${DISTNAME} here.
WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/${PKGBASE}
INSTALLATION_DIRS+=		share/doc/${PKGBASE}


do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/z.lua ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/z.lua.plugin.zsh ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/init.fish ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ranger_zlua.py ${DESTDIR}${PREFIX}/share/${PKGBASE} # Doesn't include Python hashbang at top
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.cn.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

	# z.cmd is a Batch/.bat script for Windows users. Not terribly useful for Unix-ey users, so into share/ it goes.
	# Note that we don't use ${INSTALL_SCRIPT} here since being +x'd wouldn't do anything on Windows.
	${INSTALL_DATA} ${WRKSRC}/z.cmd ${DESTDIR}${PREFIX}/share/${PKGBASE}

.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
