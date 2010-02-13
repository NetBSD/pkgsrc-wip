# $NetBSD: Makefile,v 1.1 2010/02/13 19:23:15 pettai Exp $
#

DISTNAME=	pypcap-1.1
PKGNAME=	${PYPKGPREFIX}-pypcap-1.1
CATEGORIES=	net
MASTER_SITES=	http://pypcap.googlecode.com/files/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://code.google.com/p/pypcap/
COMMENT=	Simplified object-oriented module for libpcap
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

FILES_SUBST+=   PYTHONBIN=${PYTHONBIN:Q}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
