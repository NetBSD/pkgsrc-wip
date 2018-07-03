# $NetBSD: Makefile,v 1.8 2014/05/09 07:38:47 thomasklausner Exp $

DISTNAME=	googlecalendarsync-0.4
PKGNAME=	${PYPKGPREFIX}-gcalendarsync-0.4
CATEGORIES=	www python
MASTER_SITES=	https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/googlecalendarsync/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/googlecalendarsync/
COMMENT=	Googlecalendarsync is a tool to bidirectional synchronize a local iCal

DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gdata, py-elementtree

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
.include "../../lang/python/extension.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../www/py-gdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
