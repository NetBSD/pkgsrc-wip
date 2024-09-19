# $NetBSD$

DISTNAME=	cpluff-0.1.4
CATEGORIES=	devel
MASTER_SITES=	http://www.c-pluff.org/downloads/
DESCR=		plug-in framework for C programs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.c-pluff.org/downloads/
COMMENT=	TODO: Short description of the package
LICENSE=	mit

USE_TOOLS+=		autoconf

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
