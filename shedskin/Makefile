# $NetBSD: Makefile,v 1.1.1.1 2010/04/14 20:28:19 jihbed Exp $
#

DISTNAME=	shedskin-0.3-1
CATEGORIES=	lang python
MASTER_SITES=	http://shedskin.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/shedskin/
COMMENT=	Python-to-c++ compiler
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/shedskin-0.3
USE_LANGUAGES=	c++

PYDISTUTILSPKG=yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
