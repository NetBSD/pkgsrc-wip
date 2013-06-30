# $NetBSD: Makefile,v 1.1 2013/06/30 17:21:42 guigui2 Exp $

DISTNAME=	gunicorn-0.17.4
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/g/gunicorn/
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

USE_TOOLS+=	pax
MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://gunicorn.org/
COMMENT=	Python WSGI HTTP server
LICENSE=	mit
FETCH_USING=	curl

DOCDIR=		${PREFIX}/share/doc/py-gunicorn
EXAMPLESDIR=	${PREFIX}/share/examples/py-gunicorn

# Installs the rst docs instead of generating the manpages, 
# which would require installing py-sphinx.
post-install:
	cd ${WRKSRC}/docs/source && pax -wr -pma *.rst \
		${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/examples && pax -wr -pma * \
		${DESTDIR}${EXAMPLESDIR}

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
