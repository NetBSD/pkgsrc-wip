# $NetBSD: Makefile,v 1.4 2008/12/27 16:23:52 asau Exp $
#

DISTNAME=	llvm-2.4
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/2.4/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown
USE_LANGUAGES+=	c c++
MAKE_DIRS+=	etc/llvm

CONFIGURE_ARGS=	--enable-bindings=none	# no OCaml, please!

INSTALLATION_DIRS=	lib

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only

#CONF_FILES=	share/examples/llvm/c etc/llvm/c
#CONF_FILES+=	share/examples/llvm/c++ etc/llvm/c++
#CONF_FILES+=	share/examples/llvm/cpp etc/llvm/cpp
#CONF_FILES+=	share/examples/llvm/cxx etc/llvm/cxx
#CONF_FILES+=	share/examples/llvm/ll etc/llvm/ll
#CONF_FILES+=	share/examples/llvm/st etc/llvm/st

CHECK_PORTABILITY_SKIP=	utils/buildit/build_llvm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
