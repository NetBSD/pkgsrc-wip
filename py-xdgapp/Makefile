# $NetBSD: Makefile,v 1.5 2014/01/27 19:04:45 thomasklausner Exp $

DISTNAME=	python-xdgapp-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel
MASTER_SITES=	http://launchpad.net/python-xdgapp/trunk/1.1/+download/
FETCH_USING=	curl

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	https://launchpad.net/python-xdgapp
COMMENT=	Python XDG for Applications
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-xdg>=0.17:../../devel/py-xdg

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
