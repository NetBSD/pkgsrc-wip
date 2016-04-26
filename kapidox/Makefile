# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kapidox-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Frameworks API Documentation Tools
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

.include "../../wip/kf5/Makefile.common"

PYDISTUTILSPKG=	YES
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
