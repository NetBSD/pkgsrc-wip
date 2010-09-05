# $NetBSD: Makefile,v 1.6 2010/09/05 08:57:37 gschwarz Exp $

DISTNAME=	archimedes-0.9.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=archimedes/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/archimedes/
COMMENT=	2D Monte Carlo simulation software for submicron semiconductor devices
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_FEATURES+=	getopt_long

.include "../../mk/bsd.pkg.mk"
