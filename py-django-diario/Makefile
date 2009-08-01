# $NetBSD: Makefile,v 1.2 2009/08/01 20:56:02 jihbed Exp $
#

DISTNAME=	django-diario-0.2-grigoropoulos
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-grigoropoulos//}
CATEGORIES=	www python
MASTER_SITES=	http://django-diario.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://django-diario.googlecode.com/
COMMENT=	Django Diário is a pluggable weblog application for Django Web
#LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT= user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=		yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

INSTALLATION_DIRS+=	share/doc/py-django-diario

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/py-django-diario
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DESTDIR}${PREFIX}/share/doc/py-django-diario

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
