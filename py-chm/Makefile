# $NetBSD: Makefile,v 1.3 2009/06/23 09:38:31 jihbed Exp $
#

DISTNAME=	pychm-0.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnochm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gnochm.sourceforge.net/
COMMENT=	Python bindings for the CHMLIB library

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../devel/chmlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
