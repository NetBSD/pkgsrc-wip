# $NetBSD: Makefile,v 1.1.1.1 2011/08/24 15:19:30 othyro Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

do-build:
			cd ${WRKSRC} && ${CC} -o ranmacgen macgen.c

do-install:
			${INSTALL_PROGRAM} ${WRKSRC}/ranmacgen \
				${DESTDIR}${PREFIX}/bin/ranmacgen

.include "../../mk/bsd.pkg.mk"
