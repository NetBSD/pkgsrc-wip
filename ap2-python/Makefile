# $NetBSD: Makefile,v 1.4 2004/05/02 20:57:32 blef Exp $
#

DISTNAME=	mod_python-3.0.4
CATEGORIES=	www python
MASTER_SITES=	http://www.apache.org/dist/httpd/modpython/
EXTRACT_SUFX=	.tgz

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Module that embeds the Python interpreter within the server

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
APACHE_MODULE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED= 23pth

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
