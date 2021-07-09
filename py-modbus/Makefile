# $NetBSD$

DISTNAME=	pymodbus-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymodbus/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/riptideio/pymodbus/
COMMENT=	Fully featured modbus protocol stack in python
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	${PYPKGPREFIX}-serial>=3.4:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-coverage>=4.4:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-click>=6.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-doctor>=16.3.0:../../devel/py-doctor
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2.0.4:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-pep8>=1.7.0:../../devel/py-pep8
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface>=4.4.0:../../devel/py-ZopeInterface
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.1.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.8.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.13.1:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.9.6:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.2.0:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.5.5:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-serial-asyncio>=0.5:../../wip/py-serial-asyncio
#DEPENDS+=	${PYPKGPREFIX}-wsgiref>=0.1.2:../../wip/py-wsgiref
DEPENDS+=	${PYPKGPREFIX}-tornado>=4.5.2:../../www/py-tornado


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
