# $NetBSD: Makefile,v 1.4 2010/05/03 08:46:59 jihbed Exp $
#

VERS=					0.20.0
DISTNAME=			pylint-${VERS}
PKGREVISION=    		1
CATEGORIES=			devel
MASTER_SITES=		http://pypi.python.org/packages/source/p/pylint/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://www.logilab.org/project/pylint
COMMENT=			Python code static checker
LICENSE=				gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-logilab-astng>=0.20.0:../../wip/py-logilab-astng

PKG_DESTDIR_SUPPORT=		user-destdir

.include "../../lang/python/egg.mk"
.include "../../wip/py-logilab-common/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
