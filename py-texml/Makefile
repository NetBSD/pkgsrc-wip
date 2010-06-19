# $NetBSD: Makefile,v 1.2 2010/06/19 23:44:19 jihbed Exp $
#

TEXML_VERSION=		2.0.1
DISTNAME=	texml-${TEXML_VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/getfo/texml/texml-2.0.1/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://getfo.org/texml/
COMMENT=	Convert TeXML to LaTeX or ConTeXt
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,${PREFIX}/man/man1,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
