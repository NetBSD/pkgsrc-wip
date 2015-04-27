# $NetBSD: Makefile,v 1.1 2015/04/27 21:17:15 jonthn Exp $

DISTNAME=	ctags-5.8
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GITHUB:=fishman/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fishman/ctags
COMMENT=	Exuberant (feature-filled) tagfile generator for vi, emacs and clones
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	ctags
GIT_REPO.ctags=		git://github.com/fishman/ctags
GIT_MODULE.ctags=	ctags

WRKSRC=			${WRKDIR}/${GIT_MODULE.ctags}

USE_TOOLS=		aclocal autoreconf autoconf automake autoheader gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-macro-patterns
CONFIGURE_ARGS+=	--enable-readlib
CONFIGURE_ARGS+=	--disable-readcmd
CONFIGURE_ARGS+=	--enable-custom-config=${PKG_SYSCONFDIR}/ctags.conf

CONFLICTS=	exctags-[0-9]*

pre-configure:
	cd ${WRKSRC} && autoreconf -f -i -v

.include "options.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
