# $NetBSD: Makefile,v 1.1 2012/08/06 13:42:44 mwilhelmy Exp $
#

DISTNAME=		xyssl-0.8-bsd
PKGNAME=		xyssl-0.8
CATEGORIES=		devel
MASTER_SITES=		http://polarssl.org/code/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://polarssl.org/
COMMENT=		SSL minimalist library

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.pkg.mk"
