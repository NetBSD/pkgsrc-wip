# $NetBSD: Makefile,v 1.1.1.1 2009/03/23 22:19:57 jihbed Exp $
#

DISTNAME=	pychm-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnochm/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gnochm.sourceforge.net/
COMMENT=	Bindings for CHMLIB library

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
