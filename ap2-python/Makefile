# $NetBSD: Makefile,v 1.1.1.1 2003/08/07 12:29:07 marc Exp $
#

DISTNAME=	mod_python-3.0.3
CATEGORIES=	www python
MASTER_SITES=	http://www.apache.org/dist/httpd/modpython/
EXTRACT_SUFX=	.tgz

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Module that embeds the Python interpreter within the server

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
APACHE_MODULE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED= 23pth

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
