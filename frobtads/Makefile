# $NetBSD: Makefile,v 1.1 2015/08/17 21:11:24 yhardy Exp $

GITHUB_PROJECT=	frobtads
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-1.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=realnc/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tads.org/
COMMENT=	Portable TADS toolkit
#LICENSE=	tads3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	autoconf automake libtool

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
