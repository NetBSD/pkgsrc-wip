# $NetBSD: Makefile,v 1.1 2014/07/25 22:00:58 jihbed Exp $

DISTNAME=	othman_0.2.7.orig
PKGNAME=	${PYPKGPREFIX}-othman-0.2.7
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/non-free/o/othman/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://othman.ojuba.org/
COMMENT=	Library providing access to Quranic text with a fast search index

DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

WRKSRC=		${WRKDIR}/othman-0.2.7

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt
USE_LANGUAGES=		# none

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2

.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
