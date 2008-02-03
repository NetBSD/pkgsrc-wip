# $NetBSD: Makefile,v 1.2 2008/02/03 19:33:04 hoka_adam Exp $
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

# This should be changed!
CONFIGURE_ARGS+= --enable-targets=host-only

# Prevent those .dir files to be installed accidentaly.
# I dont know how much platform independent is this. :)
# Maybe it should be handled in some other way.
#
pre-install:
	find ${WRKSRC} -name .dir | xargs rm

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
