# $NetBSD: Makefile,v 1.1 2015/04/11 14:59:45 krytarowski Exp $

GITHUB_PROJECT=	libsysstat
DISTNAME=	0.3.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=lxde/libsysstat/}
COMMENT=	Library used to query system info and statistics
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/libsysstat-0.3.0
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
