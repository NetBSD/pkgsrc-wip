# $NetBSD: Makefile,v 1.2 2008/12/10 20:07:57 cheusov Exp $
#

DISTNAME=	lua-mode-20071122
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://luaforge.net/frs/download.php/2724/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/lua-mode/
COMMENT=	Emacs major mode for editing Lua code.

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}

USE_LANGUAGES=		# none
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	${EMACS_LISPPREFIX}

EMACS_MODULES=		base

do-build:
	${EMACS_BIN} --no-init-file --no-site-file -batch \
		-f batch-byte-compile ${WRKSRC}/lua-mode.el

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} lua-mode.el lua-mode.elc \
		${DESTDIR}${EMACS_LISPPREFIX}/

#.include "../../editors/emacs/modules.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
