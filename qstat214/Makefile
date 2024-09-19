# $NetBSD: Makefile,v 0.3 2019/02/27 15:15:10 andyb Exp $

GITHUB_PROJECT=	qstat
DISTNAME=	v2.14
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=multiplay/}
DIST_SUBDIR=	${GITHUB_PROJECT}
PKGNAME=	qstat-2.14

MAINTAINER=	pkgls@gmx.net
HOMEPAGE=	https://github.com/multiplay/qstat/
COMMENT=	QStat is a program displays information about game servers

LICENSE=	artistic-2.0

DEPENDS+=	automake-[0-9]*:../../devel/automake
DEPENDS+=	autoconf-[0-9]*:../../devel/autoconf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake automake autoconf autoheader autom4te aclocal intltool pkg-config which

WRKSRC=	${WRKDIR}/qstat-2.14

pre-configure:
	cd ${WRKSRC} && \
	./autogen.sh

.include "../../mk/bsd.pkg.mk"
