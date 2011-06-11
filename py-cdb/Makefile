# $NetBSD: Makefile,v 1.1.1.1 2011/06/11 22:43:24 ryo-on Exp $
#

DISTNAME=	python-cdb-0.34
PKGNAME=	${DISTNAME:S/python-/py-/}
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
