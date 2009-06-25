# $NetBSD: Makefile,v 1.3 2009/06/25 04:54:13 christtrekker Exp $
#

DISTNAME=	lcdproc-0.5.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcdproc/}

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://lcdproc.org/
COMMENT=	Client/server software to print system info to small LCDs

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=	yes

post-patch:
	cp ${FILESDIR}/getopt.h ${WRKSRC}/shared

.include "../../mk/bsd.pkg.mk"
