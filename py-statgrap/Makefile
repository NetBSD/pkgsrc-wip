# $NetBSD: Makefile,v 1.3 2012/10/07 13:57:31 asau Exp $
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

PYDISTUTILSPKG=	yes

.include "../../devel/libstatgrab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
