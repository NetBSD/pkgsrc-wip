# $NetBSD: Makefile,v 1.2 2010/04/06 11:44:55 obache Exp $
#

DISTNAME=	tegaki-wagomu-0.3.1
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/
DISTFILES=	tegaki-wagomu-0.3${EXTRACT_SUFX} ${DEFAULT_DISTFILES}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Simple handwriting recognition engine based on DTW
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../wip/tegaki-python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

post-extract:
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/tegakiwagomu.py ${WRKSRC}
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/wagomu.h ${WRKSRC}

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
