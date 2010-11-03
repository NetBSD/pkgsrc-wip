# $NetBSD: Makefile,v 1.1.1.1 2010/11/03 21:41:24 zecrazytux Exp $

DISTNAME=	XQilla-2.2.4
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xqilla/}

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://xqilla.sourceforge.net/
COMMENT=	XQuery and XPath 2 processor
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=yes
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && ./configure --with-xerces=${PREFIX} --prefix=${PREFIX}

.include "../../wip/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
