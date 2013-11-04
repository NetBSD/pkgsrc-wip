# $NetBSD: Makefile,v 1.1 2013/11/04 00:23:46 thomasklausner Exp $

DISTNAME=	v2.0.0-rc3
PKGNAME=	torsocks-${DISTNAME:S/v//:S/-rc/rc/}
CATEGORIES=	net security
MASTER_SITES=	https://github.com/dgoulet/torsocks/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dgoulet/torsocks/
COMMENT=	Library to torify applications
LICENSE=	gnu-gpl-v2

DIST_SUBDIR=	torsocks

WRKSRC=		${WRKDIR}/torsocks-${DISTNAME:S/v//}
USE_TOOLS+=	autoreconf autoconf automake
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBC_PATH=/lib/libc.so

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
