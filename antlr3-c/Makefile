# $NetBSD: Makefile,v 1.1 2013/03/07 11:51:40 othyro Exp $
#

DISTNAME=	libantlr3c-3.4
PKGNAME=	${DISTNAME:S/lib//1:S/c/-c/1}
CATEGORIES=	textproc
MASTER_SITES=	http://www.antlr3.org/download/C/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.antlr3.org/
COMMENT=	ANother Tool for Language Recognition, C bindings
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

# Would enable -m32 on a 64 bit system if it does get the compiler
# version wrong.
CONFIGURE_ARGS +=	--disable-abiflags

.include "../../mk/bsd.pkg.mk"
