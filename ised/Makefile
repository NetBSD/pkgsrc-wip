# $NetBSD: Makefile,v 1.1.1.1 2010/09/02 12:06:52 jihbed Exp $
#

DISTNAME=	ised-2.2.2
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/ised/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://ised.sourceforge.net/
COMMENT=	Tool for generating number sequences and arithmetic evaluation
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-readline

.include "../../mk/bsd.pkg.mk"
