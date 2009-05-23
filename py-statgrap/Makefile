# $NetBSD: Makefile,v 1.1.1.1 2009/05/23 13:27:11 jihbed Exp $
#

DISTNAME=	pystatgrab-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/pystatgrab/\
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/pystatgrab/ \
		http://ftp.uk.i-scream.org/sites/ftp.i-scream.org/pub/i-scream/pystatgrab/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.i-scream.org/pystatgrab/
COMMENT=	Python bindings for the libstatgrab library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
