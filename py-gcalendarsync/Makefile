# $NetBSD: Makefile,v 1.3 2009/08/02 09:32:14 jihbed Exp $
#

DISTNAME=	googlecalendarsync-0.4
PKGNAME=	${PYPKGPREFIX}-gcalendarsync-0.4
CATEGORIES=	www python
MASTER_SITES=	http://googlecalendarsync.googlecode.com/files/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	http://code.google.com/p/googlecalendarsync/
COMMENT=	Googlecalendarsync is a tool to bidirectional synchronize a local iCal

DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../wip/py-httplib2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=		yes

DOCDIR=	${PREFIX}/share/doc/${PKGNAME}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
.include "../../lang/python/extension.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../www/py-gdata/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
