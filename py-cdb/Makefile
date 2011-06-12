# $NetBSD: Makefile,v 1.2 2011/06/12 04:17:47 ryo-on Exp $
#

DISTNAME=	python-cdb-0.34
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	databases
MASTER_SITES=	http://pilcrow.madison.wi.us/python-cdb/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pilcrow.madison.wi.us/
COMMENT=	cdb python extension module
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
