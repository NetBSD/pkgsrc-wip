# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:46 thomasklausner Exp $

VERTEX_VERSION=	0.2.0
DISTNAME=	Vertex-${VERTEX_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-vertex-${VERTEX_VERSION}
PKGREVISION=	2
CATEGORIES=	python net
MASTER_SITES=	http://milosn.no-ip.org/files/
#MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
#MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodVertex
COMMENT=	Implementation of the Q2Q protocol

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-divmod-epsilon>=0.5.0:../../wip/py-divmod-epsilon

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-twisted

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
