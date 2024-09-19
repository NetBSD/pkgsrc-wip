# $NetBSD: Makefile,v 1.1 2015/02/19 21:21:12 jihbed Exp $

DISTNAME=	system-config-printer-1.5.11
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=zdohnal/}
GITHUB_PROJECT=	system-config-printer
#GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/zdohnal/system-config-printer
COMMENT=	CUPS printer configuration tool and status applet
LICENSE=	gnu-gpl-v2

PY_PATCHPLIST=	yes

.include "../../lang/python/pyversion.mk"

USE_TOOLS+=	gmake pkg-config intltool msgfmt autoconf automake aclocal
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && \
	touch README ChangeLog && \
	autoreconf -fvi

DEPENDS+=	${PYPKGPREFIX}-cups-[0-9]*:../../print/py-cups
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject
DEPENDS+=	${PYPKGPREFIX}-curl-[0-9]*:../../www/py-curl

PY_PATCHPLIST=	yes

REPLACE_PYTHON=	*.py troubleshoot/__init__.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
