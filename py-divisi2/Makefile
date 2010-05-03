# $NetBSD: Makefile,v 1.1.1.1 2010/05/03 14:57:53 jihbed Exp $
#

DISTNAME=	Divisi2-2.0b1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-divisi2-2.0b1
CATEGORIES=	math
MASTER_SITES=	http://pypi.python.org/packages/source/D/Divisi2/
EXTRACT_SUFX=	.gz#md5=f7c6fe6443032f180bcd8dd0b9c3e8ec

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://csc.media.mit.edu/divisi
COMMENT=	Commonsense Reasoning over Semantic Networks
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/Divisi2-2.0b1


.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
