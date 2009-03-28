# $NetBSD: Makefile,v 1.5 2009/03/28 21:09:57 milosn Exp $

VERTEX_VERSION=	0.2.0
DISTNAME=	Vertex-${VERTEX_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-vertex-${VERTEX_VERSION}
PKGREVISION=	1
CATEGORIES=	python net
MASTER_SITES=	http://milosn.no-ip.org/files/
#MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
#MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodVertex
COMMENT=	An implementation of the Q2Q protocol

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../wip/py-twisted
DEPENDS+=	${PYPKGPREFIX}-divmod-epsilon>=0.5.0:../../wip/py-divmod-epsilon

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
