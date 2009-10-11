# $NetBSD: Makefile,v 1.2 2009/10/11 19:11:37 pettai Exp $
#

VER=		1.0.2
DISTNAME=	4Suite-XML-${VER}
PKGNAME=	${PYPKGPREFIX}-4Suite-${VER}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=foursuite/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://4suite.org/
COMMENT=	Open-source platform for XML and RDF processing

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

FILES_SUBST+=	PYTHONBIN=${PYTHONBIN:Q}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} setup.py config --prefix=${PREFIX}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
