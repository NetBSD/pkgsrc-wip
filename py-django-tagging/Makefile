# $NetBSD: Makefile,v 1.3 2009/08/23 22:26:59 thomasklausner Exp $
#

DISTNAME=	tagging-0.2.1
PKGNAME=	${PYPKGPREFIX}-django-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://django-tagging.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/django-tagging/
COMMENT=	Generic tagging application for Django
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24
PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-django-tagging

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/overview.txt \
		${DESTDIR}${PREFIX}/share/doc/py-django-tagging

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
