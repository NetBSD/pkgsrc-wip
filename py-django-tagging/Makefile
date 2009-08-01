# $NetBSD: Makefile,v 1.2 2009/08/01 20:54:33 jihbed Exp $
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

PYDISTUTILSPKG=		yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/doc/py-django-tagging

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/overview.txt \
		${DESTDIR}${PREFIX}/share/doc/py-django-tagging

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
