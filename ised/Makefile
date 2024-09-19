# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:41 othyro Exp $
#

DISTNAME=	ised-2.2.2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ised/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ised.sourceforge.net/
COMMENT=	Tool for generating number sequences and arithmetic evaluation
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-readline

.include "../../mk/bsd.pkg.mk"
