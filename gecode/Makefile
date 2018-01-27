# $NetBSD: Makefile,v 1.1 2013/01/10 13:47:27 fhajny Exp $
#

DISTNAME=	gecode-3.7.3
CATEGORIES=	devel
MASTER_SITES=	http://www.gecode.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gecode.org/
COMMENT=	Toolkit for developing constraint-based systems
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS=	gmake perl bash

CONFIG_SHELL=	${TOOLS_PATH.bash}

CONFIGURE_ARGS+=	--enable-examples=no

.include "../../mk/bsd.pkg.mk"
