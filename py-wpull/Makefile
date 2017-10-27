# $NetBSD$

DISTNAME=	wpull-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wpull/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chfoo/wpull/
COMMENT=	Wget-compatible web downloader and crawler
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-namedlist-[0-9]*:../../wip/py-namedlist
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-yapsy-[0-9]*:../../wip/py-yapsy

.include "../../lang/python/distutils.mk"

.if ${PYVERSSUFFIX} == "3.4" || ${PYVERSSUFFIX} == "3.5"
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-patch:
	${RM} ${WRKSRC}/wpull.egg-info/requires.txt.orig

.include "../../mk/bsd.pkg.mk"
