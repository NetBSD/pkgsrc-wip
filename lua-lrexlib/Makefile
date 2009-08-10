# $NetBSD: Makefile,v 1.5 2009/08/10 20:18:34 cheusov Exp $

.include "../../wip/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty


LICENSE=	mit

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://luaforge.net/projects/lrexlib
COMMENT=	Regexp libraries for Lua programming language

APIs=		pcre posix onig

.for i in ${APIs}
DEPENDS+=	lua-lrexlib-${i}-${VERSION}nb1:../../wip/lua-lrexlib-${i}
.endfor

META_PACKAGE=		yes

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
