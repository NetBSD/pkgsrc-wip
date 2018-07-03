# $NetBSD: Makefile,v 1.10 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=		shtoom-0.2
PKGNAME=		${PYPKGPREFIX}-shtoom-0.2
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=shtoom/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://divmod.org/trac/wiki/ShtoomProject
COMMENT=		Software VoIP telephony in Python
LICENSE=		gnu-lgpl-v2.1

DEPENDS+=		${PYPKGPREFIX}-twisted>=1.3.0:../../net/py-twisted

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.2

post-install:
	${INSTALL_DATA} ${WRKSRC}/shtoom/ui/gnomeui/shtoom.glade \
		${DESTDIR}${PREFIX}/${PYSITELIB}/shtoom/ui/gnomeui/shtoom.glade

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
