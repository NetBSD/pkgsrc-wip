# $NetBSD: Makefile,v 1.5 2009/11/22 10:56:30 gschwarz Exp $

DISTNAME=	archimedes-0.8.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=archimedes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/archimedes/
COMMENT=	2D Monte Carlo simulation software for submicron semiconductor devices

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_FEATURES+=	getopt_long

.include "../../mk/bsd.pkg.mk"
