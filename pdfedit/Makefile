# $NetBSD: Makefile,v 1.3 2007/02/20 21:36:10 lkundrak Exp $

DISTNAME=	pdfedit-0.2.5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfedit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://pdfedit.petricek.net/
COMMENT=	Editor for manipulating PDF documents

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# this could rather go into qt3-tools
PREPEND_PATH=	${QTDIR}/bin

# pdfedit bug #129
post-extract:
	${CHMOD} -R a+r ${WRKSRC}

.include "../../x11/qt3/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
