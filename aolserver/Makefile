# $NetBSD: Makefile,v 1.1.1.1 2003/03/26 00:05:26 ianharding Exp $
#

DISTNAME=	aolserver-3.4.2-src
PKGNAME=	aolserver-3.4.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aolserver/}

MAINTAINER=	iharding@pakrat.com
HOMEPAGE=	http://www.aolserver.com
COMMENT=	America Online's open-source web server

DEPENDS+=	ptl>=2.1.7:../../devel/ptl2

USE_GMAKE=	YES
WRKSRC=		${WRKDIR}/${PKGNAME}
MAKE_FLAGS=	NSHOME=${WRKSRC}

post-install:
	${MKDIR} -m 777	/var/log/nsd
	${CP} ${FILESDIR}/nsd.tcl ${PREFIX}/etc/nsd.tcl
	${CP} ${FILESDIR}/nsd ${PREFIX}/etc/rc.d/nsd

.include "../../mk/bsd.pkg.mk"
