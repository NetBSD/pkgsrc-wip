# $NetBSD$

DISTNAME=	proxychains-ng-4.14
CATEGORIES=	net
MASTER_SITES=	http://ftp.barfooze.de/pub/sabotage/tarballs/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rofl0r/proxychains-ng
COMMENT=	Chain multiple SOCKS4/SOCKS5 proxies in a transparent way
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

USE_TOOLS+=	gmake
USE_LIBTOOL=	no
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
SUBST_CLASSES+=         remove-link
SUBST_STAGE.remove-link=  post-configure
SUBST_MESSAGE.remove-link=        Removing libdl link.
SUBST_FILES.remove-link=  Makefile
SUBST_SED.remove-link=    -e 's,-ldl,,g'
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/proxychains/
	${INSTALL_DATA} ${WRKSRC}/src/proxychains.conf \
		${DESTDIR}${PREFIX}/share/examples/proxychains/

.include "../../mk/bsd.pkg.mk"
