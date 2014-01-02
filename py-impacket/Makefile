# $NetBSD: Makefile,v 1.1 2014/01/02 21:18:09 thomasklausner Exp $

DISTNAME=	impacket-0.9.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://impacket.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/impacket/
COMMENT=	Network protocols constructors and dissectors for python
LICENSE=	apache-1.1

REPLACE_PYTHON=	impacket/tds.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
