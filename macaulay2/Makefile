# $NetBSD: Makefile,v 1.1.1.1 2010/05/10 21:38:55 jihbed Exp $
#

DISTNAME=	Macaulay2-1.3.1-r10737
PKGNAME=	macaulay2-1.3.1
CATEGORIES=	math
MASTER_SITES=	http://www.math.uiuc.edu/Macaulay2/Downloads/SourceCode/
EXTRACT_SUFX=	.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uiuc.edu/Macaulay2/
COMMENT=	Macaulay2  a software system for research in algebraic geometry
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	wget>=1.12:../../net/wget

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	automake autoconf gmake bison gtar
USE_LANGUAGES=	c c++

post-extract:
	cd ${WRKDIR} && gtar -xvf ${DISTNAME}

do-configure:
	cd ${WRKSRC} && ${GMAKE} &&  ${SH} configure --prefix=${DESTDIR}${PREFIX}

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
