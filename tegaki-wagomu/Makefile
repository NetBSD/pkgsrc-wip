# $NetBSD: Makefile,v 1.1.1.1 2010/01/14 10:37:26 obache Exp $
#

DISTNAME=	tegaki-wagomu-0.3
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/0.3/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Simple handwriting recognition engine based on DTW
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../wip/tegaki-python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
