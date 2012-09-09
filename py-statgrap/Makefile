# $NetBSD: Makefile,v 1.2 2012/09/09 22:09:50 jihbed Exp $
#

DISTNAME=	pystatgrab-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/pystatgrab/\
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/pystatgrab/ \
		http://ftp.uk.i-scream.org/sites/ftp.i-scream.org/pub/i-scream/pystatgrab/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.i-scream.org/pystatgrab/
COMMENT=	Python bindings for the libstatgrab library
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
