# $NetBSD$

CATEGORIES=	net
PKGBASE=	proxychains-ng
PKGVERSION=	4.11
#PKGREVISION=	0

DISTNAME=	${PKGBASE}-${PKGVERSION}
MASTER_SITES=	https://github.com/rofl0r/proxychains-ng/releases/download/v${PKGVERSION}/
PKGNAME=	${PKGBASE}-${PKGVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	https://github.com/rofl0r/proxychains-ng
COMMENT=	Chain multiple SOCKS4/SOCKS5 proxies in a transparent way
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

USE_TOOLS+=	gmake
USE_LIBTOOL=	no
GNU_CONFIGURE=	yes

do-build:
	cd ${WRKSRC} && gmake

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/proxychains/
	${INSTALL_DATA} ${WRKSRC}/src/proxychains.conf \
		${DESTDIR}${PREFIX}/share/examples/proxychains/

.include "../../mk/bsd.pkg.mk"
