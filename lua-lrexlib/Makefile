# $NetBSD: Makefile,v 1.7 2011/05/29 08:38:07 cheusov Exp $

.include "../../wip/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/lrexlib
COMMENT=	Regexp libraries for Lua programming language
LICENSE=	mit

APIs=		pcre posix onig

.for i in ${APIs}
DEPENDS+=	lua-lrexlib-${i}-${VERSION}nb1:../../wip/lua-lrexlib-${i}
.endfor

META_PACKAGE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
