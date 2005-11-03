# $NetBSD: Makefile,v 1.10 2005/11/03 13:52:12 rillig Exp $

DISTNAME=	mod_python-3.1.3
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/modpython/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.modpython.org/
COMMENT=	Module that embeds the Python interpreter within the server

PY_PATCHPLIST=		yes
APACHE_MODULE=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-apxs=${APXS}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

PYTHON_VERSIONS_ACCEPTED= 23

.include "../../lang/python/extension.mk"
.include "../../www/apache2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
