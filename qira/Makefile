# $NetBSD$

DISTNAME=	qira-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=BinaryAnalysisPlatform/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qira.me/
COMMENT=	QEMU Interactive Runtime Analyser
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-html-[0-9]*:../../wip/py-html
# flask-socketio
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
# pyelftools
# socketIO-client
DEPENDS+=	${PYPKGPREFIX}-gevent-[0-9]*:../../net/py-gevent
DEPENDS+=	${PYPKGPREFIX}-dot-[0-9]*:../../graphics/py-dot
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
# hexdump
DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
