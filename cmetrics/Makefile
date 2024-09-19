# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:54 asau Exp $
#

DISTNAME=	CMetrics-0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=MetricsGrimoire/}
GITHUB_PROJECT=	CMetrics
GITHUB_TAG=	${PKGVERSION}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/MetricsGrimoire/CMetrics
COMMENT=	Size and complexity metrics for C source code files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	flex autoconf automake autoreconf

DOCDIR=	${PREFIX}/share/doc/cmetrics

INSTALLATION_DIRS+=	${DOCDIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
