# $NetBSD: Makefile,v 1.1.1.1 2003/09/24 06:21:43 bencollver Exp $
#

DISTNAME=	upx-1.24-src
PKGNAME=	upx-1.24
WRKSRC=		${WRKDIR}/${PKGNAME}/src
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=upx/}

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://upx.sourceforge.net/
COMMENT=	Ultimate Packer for eXecutables

BUILD_DEPENDS+=	perl>=5.6.1nb9:../../lang/perl5
DEPENDS+=	ucl>=1.01:../../devel/ucl

USE_GMAKE=	yes
MAKE_ENV+=	target=linux UCLDIR=${PREFIX}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/upx ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
