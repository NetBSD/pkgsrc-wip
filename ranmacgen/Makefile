# $NetBSD: Makefile,v 1.4 2012/11/15 20:22:14 othyro Exp $
#

DISTNAME=	macgen_src_v1.1
PKGNAME=	ran${DISTNAME:S/_src_v/-/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ranmacgen/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ranmacgen.sf.net/
COMMENT=	Random MAC address generator
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	yes
USE_LANGUAGES+=	c

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ${CC} -o ranmacgen macgen.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ranmacgen \
		${DESTDIR}${PREFIX}/bin/ranmacgen

.include "../../mk/bsd.pkg.mk"
