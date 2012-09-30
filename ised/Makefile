# $NetBSD: Makefile,v 1.2 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=	ised-2.2.2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/ised/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ised.sourceforge.net/
COMMENT=	Tool for generating number sequences and arithmetic evaluation
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-readline

.include "../../mk/bsd.pkg.mk"
