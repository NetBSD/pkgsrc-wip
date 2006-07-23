# $NetBSD: Makefile,v 1.1 2006/07/23 11:23:31 cheusov Exp $

DISTNAME=	Judy-1.0.3
PKGNAME=	libjudy-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=judy/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://judy.sourceforge.net/
COMMENT=	High-performance sparse dynamic array library

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	share/doc/${PKGBASE}

post-install:
.for i in AUTHORS ChangeLog COPYING README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
