# $NetBSD$

DISTNAME=	frida-tools-10.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/frida-tools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://frida.re/
COMMENT=	Dynamic instrumentation toolkit for developers, reverse-engineers, and security researchers (CLI tools)
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit-[0-9]*:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-frida-[0-9]*:../../wip/py-frida

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
