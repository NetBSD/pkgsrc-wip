# $NetBSD$

DISTNAME=	collectd-cgp-1
PKGNAME=        ${PHP_PKG_PREFIX}-${DISTNAME:S/-1//}
CATEGORIES=	www
GITHUB_PROJECT=	CGP
MASTER_SITES=   ${MASTER_SITE_GITHUB:=pommi/}
GITHUB_TAG=     v${DISTNAME:S/collectd-cgp-//}
EXTRACT_SUFX=   .zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/pommi/
COMMENT=	Graphical web-based front-end for visualizing RRD collected
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax unzip
AUTO_MKDIRS=	yes
EXTRACT_ONLY=	# empty

INSTALLATION_DIRS=      share/collectd-graph-panel

WRKSRC=		${WRKDIR}/CGP-1

DEPENDS+=	${PHP_PKG_PREFIX}-rrd>=1.1.3:../../databases/php-rrd

do-install:
	cd ${DESTDIR}/${PREFIX}/${INSTALLATION_DIRS} && \
	unzip -ojqL ${DISTDIR}/${DISTFILES}

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
