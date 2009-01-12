# $NetBSD: Makefile,v 1.4 2009/01/12 19:10:46 cheusov Exp $

.include "../../wip/lua-lrexlib/Makefile.version"

DISTNAME=	lua-lrexlib-${VERSION}
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

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
