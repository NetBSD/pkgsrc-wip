# $NetBSD: Makefile,v 1.3 2008/02/22 16:35:00 thomasklausner Exp $
#

DISTNAME=	llvm-2.1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/2.1/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT+=	destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown
USE_LANGUAGES+=	c c++
MAKE_DIRS+=	etc/llvm

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only

CONF_FILES=	share/examples/llvm/c etc/llvm/c
CONF_FILES+=	share/examples/llvm/c++ etc/llvm/c++
CONF_FILES+=	share/examples/llvm/cpp etc/llvm/cpp
CONF_FILES+=	share/examples/llvm/cxx etc/llvm/cxx
CONF_FILES+=	share/examples/llvm/ll etc/llvm/ll
CONF_FILES+=	share/examples/llvm/st etc/llvm/st

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
