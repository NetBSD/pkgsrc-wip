# $NetBSD: Makefile,v 1.1.1.1 2012/08/25 16:26:23 jihbed Exp $
#

DISTNAME=	regex-0.1.20120803
CATEGORIES=	textproc
MASTER_SITES=	http://pypi.python.org/packages/source/r/regex/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://code.google.com/p/mrab-regex-hg
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/regex-0.1.20120803

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
