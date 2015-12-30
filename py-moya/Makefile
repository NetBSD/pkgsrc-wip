# $NetBSD: Makefile,v 1.1 2015/09/06 23:13:52 jihbed Exp $

DISTNAME=	moya-0.5.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/m/moya/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.moyaproject.com
COMMENT=	Web development platform
LICENSE=	mit


DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-pymysql>=0.6.6:../../databases/py-pymysql
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.0.8:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.2:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-polib>=1.0.3:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.9.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6.5:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-iso8601>=0.1.10:../../time/py-iso8601
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-fs>=0.5.2:../../wip/py-fs
DEPENDS+=	${PYPKGPREFIX}-postmarkup>=1.2.2:../../wip/py-postmarkup
DEPENDS+=	${PYPKGPREFIX}-premailer>=0.5.7:../../wip/py-premailer
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.7.1:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-WebOb>=1.4:../../www/py-WebOb

WRKSRC=			${WRKDIR}/moya-0.5.20

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

REPLACE_PYTHON+=	moya/command/moya-doc

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
