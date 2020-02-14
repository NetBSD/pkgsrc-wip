# $NetBSD$

DISTNAME=	homeassistant-0.97.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=h/homeassistant/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://www.home-assistant.io/
COMMENT=	Home automation server
LICENSE=	apache-2.0

#WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${VERSION}
#EGG_INFODIR=	homeassistant-${VERSION}-py${PYVERSSUFFIX}.egg-info

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=3.7.0:../../databases/py-sqlite3

DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.5.4:../../www/py-aiohttp
#DEPENDS+=	${PYPKGPREFIX}-astral=1.10.1:../../FOO/py-astral
DEPENDS+=	${PYPKGPREFIX}-async-timeout>=3.0.1:../../devel/py-async-timeout
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.1.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-bcrypt>=3.1.7:../../security/py-bcrypt
DEPENDS+=	${PYPKGPREFIX}-certifi>=2019.6.16:../../security/py-certifi
# some notion of < 3.7, but that doesn't make sense.
#DEPENDS+=	${PYPKGPREFIX}-contextvars>=2.4:../../FOO/py-contextvars
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=0.18:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
#DEPENDS+=	${PYPKGPREFIX}-PyJWT>=1.7.1:../../FOO/py-PyJWT
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.7:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-pip>=8.0.3:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-python-slugify>=3.0.2:../../devel/py-python-slugify
DEPENDS+=	${PYPKGPREFIX}-pytz>=2019.01:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.99:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-voluptuous>=0.11.5:../../wip/py-voluptuous
#DEPENDS+=	${PYPKGPREFIX}-voluptuous-serialize>=2.1.0:../../FOO/py-voluptuous-serialize

HASS_DIR=	${VARBASE}/hass

PKG_GROUPS=	hass
PKG_USERS=	hass:hass
PKG_GECOS.hass=	Home Assistant
PKG_HOME.hass=	${HASS_DIR}

OWN_DIRS_PERMS=	${HASS_DIR} hass hass 0700

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
