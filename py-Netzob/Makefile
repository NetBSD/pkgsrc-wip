# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:44 thomasklausner Exp $

DISTNAME=	Netzob-0.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.netzob.org/repository/0.4.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netzob.org/
COMMENT=	Tool for reverse engineering communication protocols
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-gobject-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-bitarray>=0.4:../../wip/py-bitarray
DEPENDS+=	${PYPKGPREFIX}-impacket-[0-9]*:../../wip/py-impacket
# only available for FreeBSD
#DEPENDS+=	${PYPKGPREFIX}-ptrace-[0-9]*:../../wip/py-ptrace
DEPENDS+=	${PYPKGPREFIX}-pcapy-[0-9]*:../../wip/py-pcapy
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

#   python-impacket

REPLACE_PYTHON=	src/netzob/ExternalLibs/xdot.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gobject

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
