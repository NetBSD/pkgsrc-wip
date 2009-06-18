# $NetBSD: Makefile,v 1.3 2009/06/18 01:26:48 jihbed Exp $
#

DISTNAME=	foolscap-0.4.2.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/f/foolscap/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://foolscap.lothar.com/trac
COMMENT=	Foolscap contains an RPC protocol for Twisted
#LICENSE=	LICENSE

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.6:../../security/py-OpenSSL

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/foolscap-0.4.2
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED= 26 25 24

REPLACE_PYTHON+=	bin/flogtool

DOCSPEC=		${PREFIX}/share/doc/py-foolscap/specifications

INSTALLATION_DIRS=	share/doc/py-foolscap

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.xhtml \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt \
		${DESTDIR}${PREFIX}/share/doc/py-foolscap
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCSPEC}
	${INSTALL_DATA} ${WRKSRC}/doc/specifications/* \
		${DESTDIR}${DOCSPEC}


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
