# $NetBSD: Makefile,v 1.2 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	macgen_src_v1.1
PKGNAME=	ran${DISTNAME:S/_src_v/-/}
CATEGORIES=	net
MASTER_SITES=	http://sourceforge.net/projects/ranmacgen/files/ranmacgen/macgen_src/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ranmacgen.sf.net/
COMMENT=	Random MAC address generator
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
USE_LANGUAGES+=	c

WRKSRC=			${WRKDIR}

do-build:
			cd ${WRKSRC} && ${CC} -o ranmacgen macgen.c

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/ranmacgen \
				${DESTDIR}${PREFIX}/bin/ranmacgen

.include "../../mk/bsd.pkg.mk"
