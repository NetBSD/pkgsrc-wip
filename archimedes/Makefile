# $NetBSD: Makefile,v 1.7 2011/08/18 14:34:12 asau Exp $

DISTNAME=	archimedes-1.0.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=archimedes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/archimedes/
COMMENT=	2D Monte Carlo simulation software for submicron semiconductor devices
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_FEATURES+=	getopt_long

.include "../../mk/bsd.pkg.mk"
