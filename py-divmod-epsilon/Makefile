# $NetBSD: Makefile,v 1.9 2012/02/01 00:34:37 noud4 Exp $

EPSILON_VERSION=	0.5.12
DISTNAME=	Epsilon-${EPSILON_VERSION}
PKGNAME=	${PYPKGPREFIX}-divmod-epsilon-${EPSILON_VERSION}
#PKGREVISION=	2
CATEGORIES=	python
MASTER_SITES=	ftp://ftp.osuosl.org/pub/nslu2/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=         pkgsrc-wip-users@sourceforge.net
HOMEPAGE=	http://divmod.org/trac/wiki/DivmodNevow
COMMENT=	A Python utilities package, most famous for its Time class

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-twisted>=2.4.0:../../net/py-twisted

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_ACCEPTED=	26 25 24

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
