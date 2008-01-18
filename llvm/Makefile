# $NetBSD: Makefile,v 1.1.1.1 2008/01/18 16:27:13 hoka_adam Exp $
#

DISTNAME=	llvm-2.1
CATEGORIES=	lang
MASTER_SITES=	http://llvm.org/releases/2.1/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://llvm.org/
COMMENT=	Low Level Virtual Machine compiler infrastructure

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl:build chown
USE_LANGUAGES+=	c c++

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
