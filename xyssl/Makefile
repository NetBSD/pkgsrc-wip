# $NetBSD: Makefile,v 1.3 2008/03/08 21:45:21 tnn2 Exp $

DISTNAME=		xyssl-0.8-bsd
PKGNAME=		xyssl-0.8
CATEGORIES=		devel
MASTER_SITES=		http://xyssl.org/code/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://xyssl.org/
COMMENT=		SSL minimalist library

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
