# $NetBSD: Makefile,v 1.2 2004/10/20 22:13:04 lexort Exp $

DISTNAME=	g-wrap-1.9.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/g-wrap/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.nongnu.org/g-wrap/
COMMENT=	Tool for generating guile wrappers for C code

DEPENDS+=	guile-lib>=0.1.2:../../wip/guile-lib

USE_BUILDLINK3=		YES

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

USE_MAKEINFO=		YES
INFO_FILES=		g-wrap.info

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
