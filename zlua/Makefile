# $NetBSD$

DISTNAME=	z.lua-1.8.12
PKGNAME=	${DISTNAME:S/z.lua/zlua/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=skywind3000/}
GITHUB_PROJECT=	z.lua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/skywind3000/z.lua
COMMENT=	Lightweight tool that lets you quickly jump around your filesystem
LICENSE=	mit

NO_BUILD=	yes
NO_CONFIGURE=	yes
REPLACE_LUA+=	share/z.lua

# Upstream has no releases, so we don't use ${DISTNAME} here.
WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/${PKGBASE}
INSTALLATION_DIRS+=		share/doc/${PKGBASE}


do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/z.lua ${DESTDIR}${PREFIX}/share/${PKGBASE}
	ln -s -f ${PREFIX}/share/${PKGBASE}/z.lua ${DESTDIR}${PREFIX}/bin/z.lua
	${INSTALL_DATA} ${WRKSRC}/z.lua.plugin.zsh ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/init.fish ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/ranger_zlua.py ${DESTDIR}${PREFIX}/share/${PKGBASE} # Doesn't include Python hashbang at top
	${INSTALL_DATA} ${WRKSRC}/z.cmd ${DESTDIR}${PREFIX}/share/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README.cn.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/lua/application.mk"
.include "../../mk/bsd.pkg.mk"
